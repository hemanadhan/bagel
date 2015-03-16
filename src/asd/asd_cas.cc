//
// BAGEL - Parallel electron correlation program.
// Filename: asd_cas.cc
// Copyright (C) 2012 Toru Shiozaki
//
// Author: Shane Parker <shane.parker@u.northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// The BAGEL package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the BAGEL package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//

#include <src/asd/asd_cas.h>
#include <src/ci/fci/hztasks.h>
#include <src/ci/fci/prop1etask.h>

using namespace std;
using namespace bagel;

shared_ptr<Dvec> ASD_CAS::form_sigma(shared_ptr<const Dvec> ccvec, shared_ptr<const MOFile> jop) const {
  const int nstates = ccvec->ij();

  shared_ptr<const Determinants> det = ccvec->det();
  auto int_det = det->remalpha()->rembeta();

  auto sigmavec = make_shared<Dvec>(det, nstates);
  sigmavec->zero();

  const int norb = det->norb();

  shared_ptr<Matrix> h1 = jop->mo1e()->matrix();

  auto h2 = make_shared<Matrix>(norb*norb, norb*norb);
  double* h2_ptr = h2->data();
  for (int i = 0, ijkl = 0; i < norb; ++i) {
    for (int j = 0; j < norb; ++j) {
      for (int k = 0; k < norb; ++k) {
        for (int l = 0; l < norb; ++l, ++ijkl) {
          h2_ptr[ijkl] = jop->mo2e_hz(l,k,j,i) - jop->mo2e_hz(k,l,j,i);
        }
      }
    }
  }

  const int ij = norb * norb;
  auto d = make_shared<Dvec>(int_det, ij);
  auto e = make_shared<Dvec>(int_det, ij);

  for (int istate = 0; istate < nstates; ++istate) {
    shared_ptr<const Civec> cc = ccvec->data(istate);
    shared_ptr<Civec> sigma = sigmavec->data(istate);

    sigma_aa(cc, sigma, h1->data(), h2->data());

    auto cc_trans = cc->transpose();
    auto sg_trans = make_shared<Civec>(cc_trans->det());

    // sigma_bb
    sigma_aa(cc_trans, sg_trans, h1->data(), h2->data());

    sigma->ax_plus_y(1.0, *sg_trans->transpose());

    d->zero();

    sigma_2ab_1(cc, d);
    sigma_2ab_2(d, e, jop->mo2e_ptr());
    sigma_2ab_3(sigma, e);
  }

  return sigmavec;
}

shared_ptr<Dvec> ASD_CAS::form_sigma_1e(shared_ptr<const Dvec> ccvec, const double* modata) const {
  const int nstate = ccvec->ij();
  shared_ptr<const Determinants> det = ccvec->det();

  const int lbs = det->lenb();
  const int las = det->lena();

  shared_ptr<const Dvec> cc_trans = ccvec->spinflip();
  shared_ptr<const Determinants> det_trans = cc_trans->det();

  auto sigma = make_shared<Dvec>(det, nstate);
  auto sg_trans = make_shared<Dvec>(det_trans, nstate);

  TaskQueue<Prop1eTask> tasks((det->lena() + det_trans->lenb()) * nstate);

  for (int istate = 0; istate < nstate; ++istate) {
    double* target = sigma->data(istate)->data();
    for (auto& a : det->string_bits_a()) {
      tasks.emplace_back(ccvec->data(istate), a, target, modata);
      target += lbs;
    }

    target = sg_trans->data(istate)->data();
    for (auto& a : det_trans->string_bits_a()) {
      tasks.emplace_back(cc_trans->data(istate), a, target, modata);
      target += las;
    }
  }

  tasks.compute();

  sigma->ax_plus_y(1.0, *sg_trans->spinflip());

  return sigma;
}


void ASD_CAS::sigma_aa(shared_ptr<const Civec> cc, shared_ptr<Civec> sigma, const double* const h1, const double* const h2) const {
  assert(*cc->det() == *sigma->det());

  shared_ptr<const Determinants> det = cc->det();
  const int lb = cc->lenb();

  TaskQueue<HZTaskAA<double>> tasks(det->lena());

  double* target = sigma->data();
  for (auto& a : det->string_bits_a()) {
    tasks.emplace_back(cc, a, target, h1, h2);
    target += lb;
  }

  tasks.compute();
}


void ASD_CAS::sigma_2ab_1(shared_ptr<const Civec> cc, shared_ptr<Dvec> d) const {

  shared_ptr<const Determinants> base_det = cc->det();
  shared_ptr<const Determinants> int_det = base_det->remalpha()->rembeta();

  const int norb = base_det->norb();
  const int lbs = base_det->lenb();
  const double* source_base = cc->data();

  TaskQueue<HZTaskAB1<double>> tasks(norb*norb);

  for (int k = 0; k < norb; ++k) {
    for (int l = 0; l < norb; ++l) {
      double* target_base = d->data(k*norb + l)->data();
      tasks.emplace_back(int_det, lbs, source_base, target_base, k, l);
    }
  }

  tasks.compute();
}

void ASD_CAS::sigma_2ab_2(shared_ptr<Dvec> d, shared_ptr<Dvec> e, const double* mo2e_ptr) const {
  const int lenab = d->lena() * d->lenb();
  const int ij = d->ij();

  dgemm_("n", "n", lenab, ij, ij, 1.0, d->data(), lenab, mo2e_ptr, ij, 0.0, e->data(), lenab);
}

void ASD_CAS::sigma_2ab_3(shared_ptr<Civec> sigma, shared_ptr<Dvec> e) const {
  shared_ptr<const Determinants> base_det = sigma->det();
  shared_ptr<const Determinants> int_det = base_det->remalpha()->rembeta();

  const int norb = base_det->norb();
  const int lbt = base_det->lenb();
  const int lbs = int_det->lenb();
  double* target_base = sigma->data();

  for (int i = 0; i < norb; ++i) {
    for (int j = 0; j < norb; ++j) {
      const double* source_base = e->data(i*norb + j)->data();
      for (auto& aiter : int_det->phiupa(i)) {
        double *target = target_base + aiter.target*lbt;
        const double *source = source_base + aiter.source*lbs;
        for (auto& biter : int_det->phiupb(j)) {
          const double sign = static_cast<double>(aiter.sign * biter.sign);
          target[biter.target] += sign * source[biter.source];
        }
      }
    }
  }
}


tuple<shared_ptr<RDM<1>>,shared_ptr<RDM<2>>> ASD_CAS::compute_rdm12_monomer(shared_ptr<const Dvec> civec, const int i, const int ip) const {
  shared_ptr<const Civec> cbra = civec->data(i);
  shared_ptr<const Civec> cket = civec->data(ip);

  const int norb = cbra->det()->norb();
  assert(*cbra->det() == *cket->det());

  // since we consider here number conserving operators...
  auto dbra = make_shared<Dvec>(cbra->det(), norb*norb);
  dbra->zero();
  sigma_2a1(cbra, dbra);
  sigma_2a2(cbra, dbra);

  shared_ptr<Dvec> dket;
  // if bra and ket vectors are different, we need to form Sigma for ket as well.
  if (cbra != cket) {
    dket = make_shared<Dvec>(cket->det(), norb*norb);
    dket->zero();
    sigma_2a1(cket, dket);
    sigma_2a2(cket, dket);
  } else {
    dket = dbra;
  }

  return compute_rdm12_last_step(dbra, dket, cbra);
}


tuple<shared_ptr<RDM<1>>, shared_ptr<RDM<2>>> ASD_CAS::compute_rdm12_last_step(shared_ptr<const Dvec> dbra, shared_ptr<const Dvec> dket, shared_ptr<const Civec> cibra) const {
  const int norb = cibra->det()->norb();
  const int nri = dbra->lena()*dbra->lenb();
  const int ij  = norb*norb;

  if (nri != dket->lena()*dket->lenb())
    throw logic_error("FCI::compute_rdm12_last_step called with inconsistent RI spaces");

  // 1RDM
  // c^dagger <I|\hat{E}|0>
  auto rdm1 = make_shared<RDM<1>>(norb);
  dgemv_("T", nri, ij, 1.0, dket->data(0)->data(), nri, cibra->data(), 1, 0.0, rdm1->data(), 1);

  // 2RDM
  // \sum_I <0|\hat{E}|I> <I|\hat{E}|0>
  auto rdm2 = make_shared<RDM<2>>(norb);
  dgemm_("T", "N", ij, ij, nri, 1.0, dbra->data(0)->data(), nri, dket->data(0)->data(), nri, 0.0, rdm2->data(), ij);

  // sorting... a bit stupid but cheap anyway
  // This is since we transpose operator pairs in dgemm - cheaper to do so after dgemm (usually Nconfig >> norb**2).
  unique_ptr<double[]> buf(new double[norb*norb]);
  for (int i = 0; i != norb; ++i) {
    for (int k = 0; k != norb; ++k) {
      copy_n(&rdm2->element(0,0,k,i), norb*norb, buf.get());
      blas::transpose(buf.get(), norb, norb, &rdm2->element(0,0,k,i));
    }
  }

  // put in diagonal into 2RDM
  // Gamma{i+ k+ l j} = Gamma{i+ j k+ l} - delta_jk Gamma{i+ l}
  for (int i = 0; i != norb; ++i)
    for (int k = 0; k != norb; ++k)
      for (int j = 0; j != norb; ++j)
        rdm2->element(j,k,k,i) -= rdm1->element(j,i);

  return tie(rdm1, rdm2);
}


void ASD_CAS::sigma_2a1(shared_ptr<const Civec> cc, shared_ptr<Dvec> d) const {
  assert(d->det() == cc->det());
  const int lb = d->lenb();
  const int ij = d->ij();
  const double* const source_base = cc->data();
  for (int ip = 0; ip != ij; ++ip) {
    double* const target_base = d->data(ip)->data();
    for (auto& iter : cc->det()->phia(ip)) {
      const double sign = static_cast<double>(iter.sign);
      double* const target_array = target_base + iter.source*lb;
      daxpy_(lb, sign, source_base + iter.target*lb, 1, target_array, 1);
    }
  }
}


void ASD_CAS::sigma_2a2(shared_ptr<const Civec> cc, shared_ptr<Dvec> d) const {
  assert(d->det() == cc->det());
  const int la = d->lena();
  const int ij = d->ij();
  for (int i = 0; i < la; ++i) {
    const double* const source_array0 = cc->element_ptr(0, i);
    for (int ip = 0; ip != ij; ++ip) {
      double* const target_array0 = d->data(ip)->element_ptr(0, i);
      for (auto& iter : cc->det()->phib(ip)) {
        const double sign = static_cast<double>(iter.sign);
        target_array0[iter.source] += sign * source_array0[iter.target];
      }
    }
  }
}
