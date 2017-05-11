//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: finite.cc
// Copyright (C) 2012 Toru Shiozaki
//
// Author: Jae Woo Park <jwpk1201@northwestern.edu>
// Maintainer: Shiozaki group
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

#include <src/grad/gradeval.h>
#include <src/grad/finite.h>
#include <src/util/timer.h>
#include <src/wfn/construct_method.h>

using namespace std;
using namespace bagel;

shared_ptr<GradFile> FiniteGrad::compute() {
  for (auto m = idata_->begin(); m != idata_->end(); ++m) {
    const string title = to_lower((*m)->get<string>("title", ""));
    auto c = construct_method(title, *m, geom_, ref_);
    if (!c) throw runtime_error("unknown method in FiniteGrad");
    c->compute();
    ref_ = c->conv_to_ref();
  }
  energy_ = ref_->energy(target_state_);

  cout << "  Gradient evaluation with respect to " << geom_->natom() * 3 << " DOFs" << endl;
  cout << "  Finite difference size (dx) is " << setprecision(8) << dx_ << " Bohr" << endl;

  Timer timer;
  muffle_ = make_shared<Muffle>("finite.log");

  const int natom = geom_->natom();
  auto grad = make_shared<GradFile>(natom);

  for (int i = 0; i != natom; ++i) {    // atom i
    for (int j = 0; j != 3; ++j) {      // xyz
      muffle_->mute();

      double energy_plus;
      {
        auto displ = make_shared<XYZFile>(natom);
        displ->element(j,i) = dx_;
        auto geom_plus = make_shared<Geometry>(*geom_, displ, make_shared<PTree>(), false, false);
        geom_plus->print_atoms();

        if (ref_)
          ref_ = ref_->project_coeff(geom_plus);

        for (auto m = idata_->begin(); m != idata_->end(); ++m) {
          const string title = to_lower((*m)->get<string>("title", ""));
          auto c = construct_method(title, *m, geom_plus, ref_);
          if (!c) throw runtime_error("unknown method in FiniteGrad");
          c->compute();
          ref_ = c->conv_to_ref();
        }
        energy_plus = ref_->energy(target_state_);
      }

      double energy_minus;
      {
        auto displ = make_shared<XYZFile>(natom);
        displ->element(j,i) = -dx_;
        auto geom_minus = make_shared<Geometry>(*geom_, displ, make_shared<PTree>(), false, false);
        geom_minus->print_atoms();

        if (ref_)
          ref_ = ref_->project_coeff(geom_minus);

        for (auto m = idata_->begin(); m != idata_->end(); ++m) {
          const string title = to_lower((*m)->get<string>("title", ""));
          auto c = construct_method(title, *m, geom_minus, ref_);
          if (!c) throw runtime_error("unknown method in FiniteGrad");
          c->compute();
          ref_ = c->conv_to_ref();
        }
        energy_minus = ref_->energy(target_state_);
      }
      grad->element(j,i) = (energy_plus - energy_minus) / (2.0 * dx_);
      muffle_->unmute();
      stringstream ss; ss << "Finite difference evaluation (" << setw(2) << i*3+j+1 << " / " << geom_->natom() * 3 << ")";
      timer.tick_print(ss.str());
    }
  }

  grad->print(": Calculated with finite difference", 0);
  return grad;
}

template<>
shared_ptr<GradFile> FiniteNacm<CASSCF>::compute() {
  cout << "  NACME evaluation with respect to " << geom_->natom() * 3 << " DOFs" << endl;
  cout << "  Finite difference size (dx) is " << setprecision(8) << dx_ << " Bohr(s)" << endl;

  const int natom = geom_->natom();

  shared_ptr<Dvec> civ_ref = ref_->civectors()->copy();
  civ_ref->print (/*sort=*/false);

  const int nclosed = ref_->nclosed();
  const int nocc = ref_->nocc();

  Timer timer;
  muffle_ = make_shared<Muffle>("finite.log");

  auto acoeff_ref = make_shared<Matrix>(ref_->coeff()->slice(nclosed, nocc));
  auto grad = make_shared<GradFile>(natom);
  const int norb = civ_ref->det()->norb();
  auto gmo = make_shared<Matrix>(norb, norb);
  gmo->zero();

  for (int i = 0; i != natom; ++i) {      // atom i
    for (int j = 0; j != 3; ++j) {        // xyz
      muffle_->mute();

      shared_ptr<Matrix> acoeff_plus;
      shared_ptr<Dvec> civ_plus;
      {
        auto displ = make_shared<XYZFile>(natom);
        displ->element(j,i) = dx_;
        auto geom_plus = make_shared<Geometry>(*geom_, displ, make_shared<PTree>(), false, false);
        geom_plus->print_atoms();

        if (ref_)
          ref_ = ref_->project_coeff(geom_plus);

        auto energy_method = construct_method(method_, idata_, geom_plus, ref_);
        energy_method->compute();
        auto refgrad_plus = energy_method->conv_to_ref();
        acoeff_plus = make_shared<Matrix>(refgrad_plus->coeff()->slice(nclosed, nocc));
        for (int im = 0; im != acoeff_ref->mdim(); ++im) {
          double dmatch = blas::dot_product(acoeff_ref->element_ptr(0, im), acoeff_ref->ndim(), acoeff_plus->element_ptr(0,im));
          if (dmatch < 0.0)
            blas::scale_n(-1.0, acoeff_plus->element_ptr(0, im), acoeff_ref->ndim());
        }
        civ_plus = refgrad_plus->civectors()->copy();
        civ_plus->match(civ_ref);
      }

      shared_ptr<Matrix> acoeff_minus;
      shared_ptr<Dvec> civ_minus;
      {
        auto displ = make_shared<XYZFile>(natom);
        displ->element(j,i) = -dx_;
        auto geom_minus = make_shared<Geometry>(*geom_, displ, make_shared<PTree>(), false, false);
        geom_minus->print_atoms();

        if (ref_)
          ref_ = ref_->project_coeff(geom_minus);

        auto energy_method = construct_method(method_, idata_, geom_minus, ref_);
        energy_method->compute();
        auto refgrad_minus = energy_method->conv_to_ref();
        acoeff_minus = make_shared<Matrix>(refgrad_minus->coeff()->slice(nclosed, nocc));
        for (int im = 0; im != acoeff_ref->mdim(); ++im) {
          double dmatch = blas::dot_product(acoeff_ref->element_ptr(0, im), acoeff_ref->ndim(), acoeff_minus->element_ptr(0,im));
          if (dmatch < 0.0)
            blas::scale_n(-1.0, acoeff_minus->element_ptr(0, im), acoeff_ref->ndim());
        }
        civ_minus = refgrad_minus->civectors()->copy();
        civ_minus->match(civ_ref);
      }

      auto civ_diff = civ_plus->copy();
      *civ_diff -= *civ_minus;
      civ_diff->scale(1.0 / (2.0 * dx_));
      grad->element(j,i) = civ_ref->data(target_state1_)->dot_product(civ_diff->data(target_state2_));

      auto acoeff_diff = make_shared<Matrix>(*acoeff_plus - *acoeff_minus);
      acoeff_diff->scale(1.0 / (2.0 * dx_));

      auto Smn = make_shared<Overlap>(geom_);
      auto Uij = make_shared<Matrix>(*acoeff_ref % *Smn * *acoeff_diff);
      for (int ii = 0; ii != norb; ++ii) {
        for (int ij = 0; ij != norb; ++ij) {
          const int lena = civ_ref->det()->lena();
          const int lenb = civ_ref->det()->lenb();
          if (ii != ij) {
            for (auto& iter : civ_ref->det()->phia(ii, ij)) {
              size_t iaA = iter.source;
              size_t iaB = iter.target;
              double sign = static_cast<double>(iter.sign);

              for (size_t ib = 0; ib != lenb; ++ib) {
                double factor = civ_ref->data(target_state1_)->data(ib+iaB*lenb) * civ_ref->data(target_state2_)->data(ib+iaA*lenb) * sign;
                grad->element(j,i) += factor * (Uij->element(ij, ii) - Uij->element(ii, ij)) * .5;
                if ((i + j * 3) == 0) {
                  gmo->element(ij, ii) += factor * .5;
                  gmo->element(ii, ij) -= factor * .5;
                }
              }
            }
            for (size_t ia = 0; ia != lena; ++ia) {
              for (auto& iter : civ_ref->det()->phib(ii, ij)) {
                size_t ibA = iter.source;
                size_t ibB = iter.target;
                double sign = static_cast<double>(iter.sign);
                double factor = civ_ref->data(target_state1_)->data(ibB+ia*lenb) * civ_ref->data(target_state2_)->data(ibA+ia*lenb) * sign;
                grad->element(j,i) += factor * (Uij->element(ij, ii) - Uij->element(ii, ij)) * .5;
                if ((i + j * 3) == 0) {
                  gmo->element(ij, ii) += factor * .5;
                  gmo->element(ii, ij) -= factor * .5;
                }
              }
            }
          }
        }
      }
      muffle_->unmute();
      stringstream ss; ss << "Finite difference evaluation (" << setw(2) << i*3+j+1 << " / " << geom_->natom() * 3 << ")";
      timer.tick_print(ss.str());
    }
  }
  auto gfin = make_shared<Matrix>(*acoeff_ref * *gmo ^ *acoeff_ref);
  auto grad_basis = make_shared<GradFile>(natom);
  grad_basis = contract_nacme(nullptr, nullptr, nullptr, nullptr, gfin, /*numerical=*/true);
  *grad += *grad_basis;

  grad->print(": NACME calculated with finite difference", 0);

  return grad;
}
