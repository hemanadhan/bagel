//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: eribatch.h
// Copyright (C) 2009 Toru Shiozaki
//
// Author: Toru Shiozaki <shiozaki@northwestern.edu>
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

#ifndef __SRC_INTEGRAL_RYS_ERIBATCH_H
#define __SRC_INTEGRAL_RYS_ERIBATCH_H

#include <src/integral/rys/eribatch_base.h>

namespace bagel {

class ERIBatch : public ERIBatch_base {

  protected:
    void perform_VRR();
    void perform_VRR1();
    void perform_VRR2();
    void perform_VRR3();
    void root_weight(const int ps) override;

  public:

    // dummy will never be used.
    ERIBatch(const std::array<std::shared_ptr<const Shell>,4>&, const double max_density, const double dummy = 0.0, const bool dum = true,
             std::shared_ptr<StackMem> stack = nullptr);

    /// compute a batch of integrals
    void compute() override;

    constexpr static int Nblocks() { return 1; }
};

}

#endif

