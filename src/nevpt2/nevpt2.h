//
// BAGEL - Parallel electron correlation program.
// Filename: nevpt2.h
// Copyright (C) 2014 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
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


#ifndef __SRC_NEVPT2_NEVPT2_H
#define __SRC_NEVPT2_NEVPT2_H

#include <src/wfn/method.h>
#include <src/casscf/casscf.h>

namespace bagel {

class NEVPT2 : public Method {
  protected:
    std::shared_ptr<CASSCF> casscf_;
    int ncore_;
    double norm_thresh_;

    std::string abasis_;

    double energy_;

    std::tuple<std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>>
      compute_hrdm(std::shared_ptr<const Matrix> rdm1, std::shared_ptr<const Matrix> rdm2, std::shared_ptr<const Matrix> rdm3, std::shared_ptr<const Matrix> srdm2) const;
    std::tuple<std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>, std::shared_ptr<const Matrix>>
      compute_asrdm(std::shared_ptr<const Matrix> rdm1, std::shared_ptr<const Matrix> rdm2, std::shared_ptr<const Matrix> rdm3, std::shared_ptr<const Matrix> rdm4) const;

  public:
    NEVPT2(const std::shared_ptr<const PTree>, const std::shared_ptr<const Geometry>, const std::shared_ptr<const Reference> = nullptr);

    virtual void compute() override;
    virtual std::shared_ptr<const Reference> conv_to_ref() const override { return ref_; }

    double energy() const { return energy_; }
    int ncore() const { return ncore_; }
    std::string abasis() const { return abasis_; }
};

}

#endif
