//
// BAGEL - Parallel electron correlation program.
// Filename: reldf.h
// Copyright (C) 2013 Matthew Kelley
//
// Author: Matthew Kelley <matthewkelley2017@northwestern.edu>
// Maintainer: Shiozaki group
//
// This file is part of the BAGEL package.
//
// The BAGEL package is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
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


#ifndef __SRC_REL_RELDF_H
#define __SRC_REL_RELDF_H

#include <src/df/df.h>
#include <src/rel/alpha.h>
#include <src/math/zmatrix.h>
#include <src/rel/reldfbase.h>
#include <src/rel/cdmatrix.h>
#include <src/rel/reldfhalf.h>

namespace bagel {

class RelDFHalf;

class RelDF : public RelDFBase, public std::enable_shared_from_this<RelDF> {
  protected:
    std::vector<std::shared_ptr<const Alpha>> alpha_;
    std::shared_ptr<const DFDist> dfdata_;
    bool swap_;

    void set_basis() override {
      auto sigma1 = std::make_shared<const Sigma>(coord_.first);
      auto sigma2 = std::make_shared<const Sigma>(coord_.second);
      std::array<int, 2> ab = {{Basis::a, Basis::b}};
      for (auto& i : ab)
        for (auto& j : ab)
          for (auto& a : alpha_) {
            auto tmp = std::make_shared<const SpinorInfo>(std::make_pair(i,j), coord_, sigma1, sigma2, a);
            if (tmp->nonzero()) basis_.push_back(tmp);
          }
    }

  public:
    RelDF(std::shared_ptr<const DFDist>, std::pair<int, int>, const std::vector<int>);
    RelDF(const RelDF&) = delete;
    RelDF(const RelDF&, bool);
    RelDF() = delete;

    std::shared_ptr<const DFDist> df() const { return dfdata_; }
    bool not_diagonal() const { return coord_.first != coord_.second; }
    bool swapped() const { return swap_; }
    std::shared_ptr<const RelDF> swap() const;

    std::vector<std::shared_ptr<RelDFHalf>>
        compute_half_transform(std::array<std::shared_ptr<const Matrix>,4> r,
                               std::array<std::shared_ptr<const Matrix>,4> i) const;

    std::vector<std::shared_ptr<ZMatrix>> compute_Jop(std::list<std::shared_ptr<const CDMatrix>>& cd) const;
};

}

#endif