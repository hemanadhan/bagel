//
// Newint - Parallel electron correlation program.
// Filename: naibatch_base.cc
// Copyright (C) 2012 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the Newint package (to be renamed).
//
// The Newint package is free software; you can redistribute it and\/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// The Newint package is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public License
// along with the Newint package; see COPYING.  If not, write to
// the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//


#include <src/rysint/naibatch_base.h>
#define PI 3.1415926535897932
#define SQRTPI2 0.886226925452758013649083741671

using namespace std;

NAIBatch_base::NAIBatch_base(const std::vector<std::shared_ptr<Shell> >& _info, const std::shared_ptr<Geometry> gm, const int deriv,
                             const int L, const double A)
 : RysInt(_info), geom_(gm), L_(L), A_(A) {

  deriv_rank_ = deriv;
  const double integral_thresh = PRIM_SCREEN_THRESH; 

  if (_info.size() != 2) throw logic_error("NAIBatch_base should be called with shell pairs");
  shared_ptr<Shell> dum(new Shell(_info[0]->spherical()));
  basisinfo_.push_back(dum); basisinfo_.push_back(dum);

  // natom_ 
  natom_ = geom_->natom() * (2 * L + 1);

  // cartesian to spherical tranformation has not yet been implemented.
  const bool spherical = false;
  if (!_info[0]->spherical())
    throw logic_error("cartesian to spherical tranformation has not yet been implemented."); 

  set_swap_info();
  set_ab_cd();
  set_prim_contsizes();

  int asize_intermediate, asize_final, dum0, dum1;
  tie(asize_intermediate, dum0, asize_final, dum1) = set_angular_info();

  allocate_data(asize_intermediate, 1, asize_final, 1);

  allocate_arrays(primsize_*natom_);

  compute_ssss(integral_thresh);

  root_weight(primsize_*natom_);

}

void NAIBatch_base::compute_ssss(const double integral_thresh) {
  screening_size_ = 0;

  const vector<double> exp0 = basisinfo_[0]->exponents();
  const vector<double> exp1 = basisinfo_[1]->exponents();

  int index = 0;
  vector<shared_ptr<Atom> > atoms = geom_->atoms();

  const double onepi2 = 1.0 / (PI * PI);
  const double sqrtpi = ::sqrt(PI);
  for (auto expi0 = exp0.begin(); expi0 != exp0.end(); ++expi0) { 
    for (auto expi1 = exp1.begin(); expi1 != exp1.end(); ++expi1) { 
      for (auto aiter = atoms.begin(); aiter != atoms.end(); ++aiter, ++index) {
        double Z = static_cast<double>((*aiter)->atom_number()); 
        const double cxp = *expi0 + *expi1;
        xp_[index] = cxp;
        const double ab = *expi0 * *expi1; 
        const double cxp_inv = 1.0 / cxp;
        p_[index * 3    ] = (basisinfo_[0]->position(0) * *expi0 + basisinfo_[1]->position(0) * *expi1) * cxp_inv;
        p_[index * 3 + 1] = (basisinfo_[0]->position(1) * *expi0 + basisinfo_[1]->position(1) * *expi1) * cxp_inv;
        p_[index * 3 + 2] = (basisinfo_[0]->position(2) * *expi0 + basisinfo_[1]->position(2) * *expi1) * cxp_inv;
        const double Eab = ::exp(-(AB_[0] * AB_[0] + AB_[1] * AB_[1] + AB_[2] * AB_[2]) * (ab * cxp_inv) );
        coeff_[index] = - 2 * Z * PI * cxp_inv * Eab; 
        const double PCx = p_[index * 3    ] - (*aiter)->position(0);
        const double PCy = p_[index * 3 + 1] - (*aiter)->position(1);
        const double PCz = p_[index * 3 + 2] - (*aiter)->position(2);
        const double T = cxp * (PCx * PCx + PCy * PCy + PCz * PCz); 
        const double sqrtt = ::sqrt(T);
        const double ss = - coeff_[index] * ::pow(4.0 * ab * onepi2, 0.75) * (T > 1.0e-15 ? sqrtpi * ::erf(sqrtt) / sqrtt * 0.5 : 1.0); 
        if (ss > integral_thresh) {
          T_[index] = T;
          screening_[screening_size_] = index;
          ++screening_size_;
        } else {
          T_[index] = -1.0;
          coeff_[index] = 0.0;
        }
      }
    }
  }
}
