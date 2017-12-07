//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: multisite.cc
// Copyright (C) 2014 Shane Parker
//
// Author: Shane Parker <shane.parker@u.northwestern.edu>
// Maintainer: NU theory
//
// This file is part of the BAGEL package.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <src/asd/multisite/multisite.h>
#include <src/scf/hf/fock.h>
#include <src/mat1e/overlap.h>
#include <src/wfn/localization.h>
#include <src/util/io/moldenout.h>

using namespace std;
using namespace bagel;

// constructor
MultiSite::MultiSite(shared_ptr<const PTree> input, shared_ptr<const Reference> ref, const int nsites) : input_(input), hf_ref_(ref), nsites_(nsites) {
  cout << string(60, '=') << endl;
  cout << string(15, ' ') << "Construct MultiSite" << endl;
  cout << string(60, '=') << endl;

  charge_ = input_->get<int>("charge", 0);
  nspin_ = input_->get<int>("nspin", 0);

  active_electrons_ = input_->get_vector<int>("active_electrons");
  active_sizes_ = input_->get_vector<int>("active_sizes");
  region_sizes_ = input_->get_vector<int>("region_sizes");
  assert(accumulate(region_sizes_.begin(), region_sizes_.end(), 0) == hf_ref_->geom()->natom());
  
  // collect orbital subspaces info
  const int nactele = accumulate(active_electrons_.begin(), active_electrons_.end(), 0);
  const int nclosed = (hf_ref_->geom()->nele() - charge_ - nactele) / 2;
  assert((hf_ref_->geom()->nele() - charge_ - nactele) % 2 == 0);
  const int nactive = accumulate(active_sizes_.begin(), active_sizes_.end(), 0);
  const int nvirt = hf_ref_->coeff()->mdim() - nclosed - nactive;

  sref_ = make_shared<Reference>(hf_ref_->geom(), hf_ref_->coeff(), nclosed, nactive, nvirt);
}


void MultiSite::compute() {
  // construct Fock Matrix 
  shared_ptr<const Fock<1>> fock;
  {
    shared_ptr<const Matrix> density = hf_ref_->coeff()->form_density_rhf(hf_ref_->nclosed());
    const MatView ccoeff = hf_ref_->coeff()->slice(0, hf_ref_->nclosed());
    fock = make_shared<const Fock<1>>(hf_ref_->geom(), hf_ref_->hcore(), density, ccoeff);
  }

  // localize closed and virtual orbitals (optional)
  shared_ptr<const PTree> localization_data = input_->get_child_optional("localization");
  if (localization_data) {
    cout << "Doing localization" << endl;
    localize(localization_data, fock);
    MoldenOut mfile("localized.molden");
    mfile << sref_->geom();
    mfile << sref_;
  }

  // two options : 1) manually assign active orbitals to subspaces  2) use projection to assign automatically
  set_active_orbitals();

  // canonicalize active orbitals within each subspace
  canonicalize(fock);

  // tmp function, only for debugging
  run_fci();
}


void MultiSite::localize(shared_ptr<const PTree> localize_data, shared_ptr<const Matrix> fock) {
  string localizemethod = localize_data->get<string>("algorithm", "pm");

  shared_ptr<OrbitalLocalization> localization;
  auto input_data = make_shared<PTree>(*localize_data);
  input_data->erase("virtual"); input_data->put("virtual", true);
  if (input_data->get_child_optional("region_sizes")) {
    cout << "WARNING : The region_sizes keyword in localization input will be overwritten by that from MultiSite input." << endl;
    input_data->erase("region_sizes");
  }
  
  if (localizemethod == "region") {
    localization = make_shared<RegionLocalization>(input_data, hf_ref_, region_sizes_);
  } else if (localizemethod == "pm" || localizemethod == "pipek-mezey") {
    input_data->erase("type"); input_data->put("type", "region");
    localization = make_shared<PMLocalization>(input_data, hf_ref_, region_sizes_);
  } else throw runtime_error("Unrecognized orbital localization method");

  shared_ptr<const Matrix> local_coeff = localization->localize();
  vector<pair<int, int>> orbital_subspaces = localization->orbital_subspaces();
  assert(orbital_subspaces.size() == 2); // closed and active only

  vector<pair<int, int>> region_bounds;
  {
    int atom_start = 0;
    int current = 0;
    for (int natom : region_sizes_) {
      const int bound_start = current;
      for (int iatom = 0; iatom != natom; ++iatom)
        current += hf_ref_->geom()->atoms(atom_start+iatom)->nbasis();
      region_bounds.emplace_back(bound_start, current);
      atom_start += natom;
    }
  }
  assert(region_bounds.size() == nsites_);

  vector<vector<pair<int, int>>> site_bounds;

  assert(hf_ref_->coeff()->mdim() == accumulate(orbital_subspaces.begin(), orbital_subspaces.end(), 0ull,
                               [] (int o, const pair<int, int>& p) { return o + p.second - p.first; }));

  Matrix ShalfC = static_cast<Matrix>(Overlap(hf_ref_->geom()));
  ShalfC.sqrt();
  ShalfC *= *local_coeff;

  auto out_coeff = local_coeff->clone();
  
  for (const pair<int, int>& subspace : orbital_subspaces) {
    vector<set<int>> orbital_sets(nsites_);
    const int nsuborbs = subspace.second - subspace.first;

    vector<pair<int, int>> subspace_site_bounds;

    vector<vector<double>> lowdin_populations(nsuborbs);
    for (auto& p : lowdin_populations)
      p.resize(nsites_);

    Matrix Q(nsuborbs, nsuborbs);
    for (int site = 0; site != nsites_; ++site) {
      const pair<int, int> bounds = region_bounds[site];
      const int nregbasis = bounds.second - bounds.first;
      dgemm_("T", "N", nsuborbs, nsuborbs, nregbasis, 1.0, ShalfC.element_ptr(bounds.first, subspace.first), ShalfC.ndim(),
                                                           ShalfC.element_ptr(bounds.first, subspace.first), ShalfC.ndim(), 
                                                      0.0, Q.data(), Q.ndim());
      for (int orb = 0; orb != nsuborbs; ++orb)
        lowdin_populations[orb][site] = Q(orb, orb) * Q(orb, orb);
    }

    for (int orb = 0; orb != nsuborbs; ++orb) {
      //pick the largest value to assign it to sites
      vector<double>& pops = lowdin_populations[orb];
      auto maxiter = max_element(pops.begin(), pops.end());
      const int maxsite = maxiter - pops.begin();
      orbital_sets[maxsite].insert(orb + subspace.first);
    }

    size_t imo = subspace.first;

    for (auto& subset : orbital_sets) {
      if (subset.empty()) continue;
      Matrix subspace(out_coeff->ndim(), subset.size());
      int pos = 0;
      for (const int& i : subset)
        copy_n(local_coeff->element_ptr(0, i), local_coeff->ndim(), subspace.element_ptr(0, pos++));

      Matrix subfock(subspace % *fock * subspace);
      VectorB eigs(subspace.ndim());
      subfock.diagonalize(eigs);
      subspace *= subfock;

      copy_n(subspace.data(), subspace.size(), out_coeff->element_ptr(0, imo));
      subspace_site_bounds.emplace_back(imo, imo+subset.size());
      imo += subset.size();
    }
    site_bounds.emplace_back(move(subspace_site_bounds));
  }

  assert(site_bounds.front().front().first < site_bounds.back().front().first);
  
  sref_ = make_shared<Reference>(hf_ref_->geom(), make_shared<Coeff>(move(*out_coeff)), sref_->nclosed(), sref_->nact(), sref_->nvirt());
}


void MultiSite::set_active_orbitals() {
  auto assign_active = input_->get_child_optional("actorb_subspaces");
  
  if (assign_active) {
    ///> active subspaces info is provided, just reorder the orbitals
    if (assign_active->size() != nsites_)
      throw logic_error("Must specify active spaces for all of the sites");
    
    auto out_coeff = sref_->coeff()->clone();

    vector<set<int>> active_orbitals;
    set<int> active_set;
    for (auto site : *assign_active) {
      vector<int> active_orbs = site->get_vector<int>("");
      for_each(active_orbs.begin(), active_orbs.end(), [](int& x) { x--; });
      active_orbitals.emplace_back(active_orbs.begin(), active_orbs.end());
      active_set.insert(active_orbs.begin(), active_orbs.end());
    }
    assert(active_set.size() == sref_->nact());
    
    const int nclosed = sref_->nclosed();
    const int nactive = sref_->nact();
    const int multisitebasis = hf_ref_->geom()->nbasis();
    int closed_position = 0;
    int active_position = nclosed;
    int virt_position = nclosed + nactive;
  
    auto in_coeff = sref_->coeff();
    assert(in_coeff->ndim() == multisitebasis);
  
    for (auto site : active_orbitals) {
      for (int aorb : site)
        copy_n(in_coeff->element_ptr(0, aorb), multisitebasis, out_coeff->element_ptr(0, active_position++));
    }
    for (int i = 0; i != in_coeff->mdim(); ++i) {
      if (active_set.count(i) == 0)
        copy_n(in_coeff->element_ptr(0, i), multisitebasis, out_coeff->element_ptr(0, (closed_position < nclosed ? closed_position++ : virt_position++)));
    }
    assert(virt_position == in_coeff->mdim());
    
    sref_ = make_shared<Reference>(sref_->geom(), make_shared<Coeff>(move(*out_coeff)), sref_->nclosed(), sref_->nact(), sref_->nvirt());
  } else {
    ///> if no manually assigned active orbital subspaces, do projection
    shared_ptr<const PTree> projection_data = input_->get_child_optional("projection");
    if (!projection_data) throw runtime_error("Missing input information : \"projection\"");
    cout << "Doing projection" << endl;

    project_active(projection_data);
    
    MoldenOut mfile("projected.molden");
    mfile << sref_->geom();
    mfile << sref_;
  }
}


void MultiSite::project_active(shared_ptr<const PTree> input) {
  auto out_coeff = sref_->coeff()->clone();

  const int nclosed = sref_->nclosed();
  const int nactive = sref_->nact();
  const int multisitebasis = hf_ref_->geom()->nbasis();

  // reorder coeff to closed-active-virtual
  vector<int> active_vec = input->get_vector<int>("active_set");
  set<int> active_set;  active_set.insert(active_vec.begin(), active_vec.end());
  assert(active_set.size() == nactive);
  int closed_position = 0;
  int active_position = nclosed;
  int virt_position = nclosed + nactive;
  for (auto& aorb : active_set)
    copy_n(sref_->coeff()->element_ptr(0, aorb), multisitebasis, out_coeff->element_ptr(0, active_position++));
  assert(active_position == virt_position);
  for (int iorb = 0; iorb != out_coeff->mdim(); ++iorb)
    if (active_set.count(iorb) == 0)
      copy_n(sref_->coeff()->element_ptr(0, iorb), multisitebasis, out_coeff->element_ptr(0, (closed_position < nclosed ? closed_position++ : virt_position++)));
  assert(closed_position == nclosed);
  assert(virt_position == out_coeff->mdim());

  // delocalized active orbital set
  auto act_orbs = make_shared<Matrix>(multisitebasis, nactive);
  copy_n(sref_->coeff()->element_ptr(0, nclosed), multisitebasis*nactive, act_orbs->data());

  // region bound info
  vector<pair<int, int>> region_bounds;
  int atomstart = 0; int basis_start = 0;
  for (int isize : region_sizes_) {
    int nbasis = 0;
    for (int iatom = atomstart; iatom != atomstart+isize; ++iatom)
      nbasis += sref_->geom()->atoms(iatom)->nbasis();
    region_bounds.emplace_back(basis_start, basis_start+nbasis);
    atomstart += isize;
    basis_start += nbasis;
  }

  // do SVD and project coeff
  int pos = nclosed;
  for (int isite = 0; isite != nsites_; ++isite) {
    pair<int, int> bounds = region_bounds[isite];
    const int ntot = act_orbs->mdim();
    const int nsub = active_sizes_[isite];
    const int nbasis = bounds.second - bounds.first;
    auto actorb = act_orbs->get_submatrix(bounds.first, 0, nbasis, ntot);
    Matrix SVD(*actorb % *actorb);
    VectorB eigs(SVD.ndim());
    SVD.diagonalize(eigs);
    for (auto& e : eigs) cout << e << endl;
    const MatView trans_mat(SVD.slice(ntot-nsub, nsub));
    const MatView subcoeff(*act_orbs * trans_mat);
    copy_n(subcoeff.data(), subcoeff.size(), out_coeff->element_ptr(0, pos));
    pos += nsub;
  }

  sref_ = make_shared<Reference>(sref_->geom(), make_shared<Coeff>(move(*out_coeff)), nclosed, nactive, sref_->nvirt());
}


void MultiSite::canonicalize(shared_ptr<const Matrix> fock) {
  //canonicalize active orbitals within subspace
  const int nclosed = sref_->nclosed();
  
  // rotate within each active subspace
  MatView active_mos = sref_->coeff()->slice(nclosed, nclosed+sref_->nact());
  Matrix fock_mo(active_mos % *fock * active_mos);
  VectorB eigs(active_mos.mdim());
  shared_ptr<Matrix> active_transformation = fock_mo.diagonalize_blocks(eigs, active_sizes_);
  Matrix transformed_mos(active_mos * *active_transformation);
  shared_ptr<Matrix> scoeff = sref_->coeff()->copy();
  scoeff->copy_block(0, nclosed, scoeff->ndim(), transformed_mos.mdim(), transformed_mos);

  sref_ = make_shared<Reference>(*sref_, make_shared<Coeff>(move(*scoeff)));
}


shared_ptr<Reference> MultiSite::build_reference(const int site, const vector<bool> meanfield) const {
  assert(meanfield.size() == nsites_ && site < nsites_ && site >=0);

  vector<shared_ptr<const MatView>> closed_orbitals = { make_shared<MatView>(sref_->coeff()->slice(0, sref_->nclosed())) };
  const int act_start = accumulate(active_sizes_.begin(), active_sizes_.begin()+site, sref_->nclosed());
  const int act_fence = act_start + active_sizes_.at(site);
  const MatView active_orbitals = sref_->coeff()->slice(act_start, act_fence);

  int current = sref_->nclosed();
  for (int i = 0; i != nsites_; ++i) {
    if (meanfield[i] && i != site)
      closed_orbitals.push_back(make_shared<const MatView>(sref_->coeff()->slice(current, current+(active_electrons_.at(i)+1)/2)));
    current += active_sizes_.at(i);
  }

  const int nclosed = accumulate(closed_orbitals.begin(), closed_orbitals.end(), 0, [](int x, shared_ptr<const MatView>m) { return x + m->mdim(); });
  const int nact = active_orbitals.mdim();

  auto out = make_shared<Matrix>(sref_->geom()->nbasis(), nclosed+nact);

  current = 0;
  closed_orbitals.push_back(make_shared<MatView>(active_orbitals));
  for (auto& orbitals : closed_orbitals) {
    copy_n(orbitals->data(), orbitals->size(), out->element_ptr(0, current));
    current += orbitals->mdim();
  }

  return make_shared<Reference>(sref_->geom(), make_shared<Coeff>(move(*out)), nclosed, nact, 0);
}


#include <src/ci/fci/knowles.h>
void MultiSite::run_fci() const {
  auto fci_info = input_->get_child_optional("fci");
  if(!fci_info) {
    cout << "No FCI info provided, skipping MultiSite debugging.." << endl;
    return;
  }

  auto fci = make_shared<KnowlesHandy>(fci_info, sref_->geom(), sref_);
  fci->compute();
  cout << " * FCI energy : " << setprecision(12) << fci->energy(0) << endl;
}
