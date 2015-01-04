//
// BAGEL - Parallel electron correlation program.
// Filename: CASPT2_tasks30.cc
// Copyright (C) 2014 Shiozaki group
//
// Author: Shiozaki group <shiozaki@northwestern.edu>
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


#include <src/smith/CASPT2_tasks30.h>

using namespace std;
using namespace bagel;
using namespace bagel::SMITH;
using namespace bagel::SMITH::CASPT2;

void Task1450::Task_local::compute() {
  const Index a3 = b(0);
  const Index x1 = b(1);
  // tensor label: I1715
  std::unique_ptr<double[]> odata = out()->move_block(a3, x1);
  {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(a3, x1);
    sort_indices<0,1,1,1,-1,4>(i0data, odata, a3.size(), x1.size());
  }
  out()->put_block(odata, a3, x1);
}

void Task1451::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c3 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a2, c3, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a2, c3, x1)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a2.size(), c3.size(), x1.size());
      // tensor label: I1737
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c3)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c3.size(),
             1.0, i0data_sorted, a2.size()*c3.size(), i1data_sorted, a2.size()*c3.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1452::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c3 = b(3);
  // tensor label: I1737
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c3);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x2, x3, a2, c3)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x2, x3, a2, c3), 0.0);
  for (auto& c1 : *range_[0]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, c3);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, c3)]);
    sort_indices<0,1,0,1,1,1>(i0data, i0data_sorted, c1.size(), c3.size());
    // tensor label: I1738
    std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
    sort_indices<3,0,1,2,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
    dgemm_("T", "N", c3.size(), x2.size()*x3.size()*a2.size(), c1.size(),
           1.0, i0data_sorted, c1.size(), i1data_sorted, c1.size(),
           1.0, odata_sorted, c3.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, c3.size(), x2.size(), x3.size(), a2.size());
  out()->put_block(odata, x2, x3, a2, c3);
}

void Task1453::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1738
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    sort_indices<3,2,1,0,1,1,1,4>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1454::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a3 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a3, c1, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a3, c1, x1)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a3.size(), c1.size(), x1.size());
      // tensor label: I1741
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, c1, a3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, c1, a3)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), c1.size(), a3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), c1.size()*a3.size(),
             1.0, i0data_sorted, c1.size()*a3.size(), i1data_sorted, c1.size()*a3.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1455::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index c1 = b(2);
  const Index a3 = b(3);
  // tensor label: I1741
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, c1, a3);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x2, x3, c1, a3)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x2, x3, c1, a3), 0.0);
  for (auto& a2 : *range_[2]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(a3, a2);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(a3, a2)]);
    sort_indices<1,0,0,1,1,1>(i0data, i0data_sorted, a3.size(), a2.size());
    // tensor label: I1742
    std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
    sort_indices<2,0,1,3,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
    dgemm_("T", "N", a3.size(), x2.size()*x3.size()*c1.size(), a2.size(),
           1.0, i0data_sorted, a2.size(), i1data_sorted, a2.size(),
           1.0, odata_sorted, a3.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, a3.size(), x2.size(), x3.size(), c1.size());
  out()->put_block(odata, x2, x3, c1, a3);
}

void Task1456::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1742
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    sort_indices<3,2,1,0,1,1,-1,4>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1457::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c3 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c3, a2, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c3, a2, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c3.size(), a2.size(), x0.size(), x1.size());
      // tensor label: I1748
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c3)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c3.size(),
             1.0, i0data_sorted, a2.size()*c3.size(), i1data_sorted, a2.size()*c3.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1458::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c3 = b(3);
  // tensor label: I1748
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c3);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x2, x3, a2, c3)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x2, x3, a2, c3), 0.0);
  for (auto& c1 : *range_[0]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, c3);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, c3)]);
    sort_indices<0,1,0,1,1,1>(i0data, i0data_sorted, c1.size(), c3.size());
    // tensor label: I1749
    std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
    sort_indices<3,0,1,2,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
    dgemm_("T", "N", c3.size(), x2.size()*x3.size()*a2.size(), c1.size(),
           1.0, i0data_sorted, c1.size(), i1data_sorted, c1.size(),
           1.0, odata_sorted, c3.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, c3.size(), x2.size(), x3.size(), a2.size());
  out()->put_block(odata, x2, x3, a2, c3);
}

void Task1459::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1749
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1460::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a3 : *range_[2]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a3, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a3, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a3.size(), x0.size(), x1.size());
      // tensor label: I1752
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, c1, a3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, c1, a3)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), c1.size(), a3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), c1.size()*a3.size(),
             1.0, i0data_sorted, c1.size()*a3.size(), i1data_sorted, c1.size()*a3.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1461::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index c1 = b(2);
  const Index a3 = b(3);
  // tensor label: I1752
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, c1, a3);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x2, x3, c1, a3)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x2, x3, c1, a3), 0.0);
  for (auto& a2 : *range_[2]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(a3, a2);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(a3, a2)]);
    sort_indices<1,0,0,1,1,1>(i0data, i0data_sorted, a3.size(), a2.size());
    // tensor label: I1753
    std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
    sort_indices<2,0,1,3,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
    dgemm_("T", "N", a3.size(), x2.size()*x3.size()*c1.size(), a2.size(),
           1.0, i0data_sorted, a2.size(), i1data_sorted, a2.size(),
           1.0, odata_sorted, a3.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, a3.size(), x2.size(), x3.size(), c1.size());
  out()->put_block(odata, x2, x3, c1, a3);
}

void Task1462::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1753
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    sort_indices<3,2,1,0,1,1,1,2>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1463::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a2, x3, x2)]);
      sort_indices<1,0,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a2.size(), x3.size(), x2.size());
      // tensor label: I1768
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, c1, a2);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, c1, a2)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), c1.size(), a2.size());
      dgemm_("T", "N", x2.size()*x3.size(), x1.size()*x0.size(), c1.size()*a2.size(),
             1.0, i0data_sorted, c1.size()*a2.size(), i1data_sorted, c1.size()*a2.size(),
             1.0, odata_sorted, x2.size()*x3.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1464::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index c1 = b(2);
  const Index a2 = b(3);
  // tensor label: I1768
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, c1, a2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, c1, a2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, c1, a2), 0.0);
  for (auto& a3 : *range_[2]) {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a3, c1, a2);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a3, c1, a2)]);
    sort_indices<1,0,2,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a3.size(), c1.size(), a2.size());
    // tensor label: I1769
    std::unique_ptr<double[]> i1data = in(1)->get_block(a3, x1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(a3, x1)]);
    sort_indices<0,1,0,1,1,1>(i1data, i1data_sorted, a3.size(), x1.size());
    dgemm_("T", "N", x0.size()*c1.size()*a2.size(), x1.size(), a3.size(),
           1.0, i0data_sorted, a3.size(), i1data_sorted, a3.size(),
           1.0, odata_sorted, x0.size()*c1.size()*a2.size());
  }
  sort_indices<3,0,1,2,1,1,1,1>(odata_sorted, odata, x0.size(), c1.size(), a2.size(), x1.size());
  out()->put_block(odata, x1, x0, c1, a2);
}

void Task1465::Task_local::compute() {
  const Index a3 = b(0);
  const Index x1 = b(1);
  // tensor label: I1769
  std::unique_ptr<double[]> odata = out()->move_block(a3, x1);
  {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(a3, x1);
    sort_indices<0,1,1,1,1,2>(i0data, odata, a3.size(), x1.size());
  }
  out()->put_block(odata, a3, x1);
}

void Task1466::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index c1 = b(2);
  const Index a2 = b(3);
  // tensor label: I1768
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, c1, a2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, c1, a2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, c1, a2), 0.0);
  for (auto& a3 : *range_[2]) {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a2, c1, a3);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a2, c1, a3)]);
    sort_indices<3,0,1,2,0,1,1,1>(i0data, i0data_sorted, x0.size(), a2.size(), c1.size(), a3.size());
    // tensor label: I1773
    std::unique_ptr<double[]> i1data = in(1)->get_block(a3, x1);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(a3, x1)]);
    sort_indices<0,1,0,1,1,1>(i1data, i1data_sorted, a3.size(), x1.size());
    dgemm_("T", "N", x0.size()*a2.size()*c1.size(), x1.size(), a3.size(),
           1.0, i0data_sorted, a3.size(), i1data_sorted, a3.size(),
           1.0, odata_sorted, x0.size()*a2.size()*c1.size());
  }
  sort_indices<3,0,2,1,1,1,1,1>(odata_sorted, odata, x0.size(), a2.size(), c1.size(), x1.size());
  out()->put_block(odata, x1, x0, c1, a2);
}

void Task1467::Task_local::compute() {
  const Index a3 = b(0);
  const Index x1 = b(1);
  // tensor label: I1773
  std::unique_ptr<double[]> odata = out()->move_block(a3, x1);
  {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(a3, x1);
    sort_indices<0,1,1,1,-1,4>(i0data, odata, a3.size(), x1.size());
  }
  out()->put_block(odata, a3, x1);
}

void Task1468::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a3 : *range_[2]) {
    for (auto& c2 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a3, c2, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a3, c2, x1)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a3.size(), c2.size(), x1.size());
      // tensor label: I1841
      std::unique_ptr<double[]> i1data = in(1)->get_block(a3, c2, x3, x2);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(a3, c2, x3, x2)]);
      sort_indices<0,1,2,3,0,1,1,1>(i1data, i1data_sorted, a3.size(), c2.size(), x3.size(), x2.size());
      dgemm_("T", "N", x0.size()*x1.size(), x3.size()*x2.size(), a3.size()*c2.size(),
             1.0, i0data_sorted, a3.size()*c2.size(), i1data_sorted, a3.size()*c2.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,2,3,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x3.size(), x2.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1469::Task_local::compute() {
  const Index a3 = b(0);
  const Index c2 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1841
  std::unique_ptr<double[]> odata = out()->move_block(a3, c2, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(a3, c2, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(a3, c2, x3, x2), 0.0);
  for (auto& a1 : *range_[2]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(x2, a1);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x2, a1)]);
    sort_indices<1,0,0,1,1,1>(i0data, i0data_sorted, x2.size(), a1.size());
    // tensor label: I1842
    std::unique_ptr<double[]> i1data = in(1)->get_block(a3, c2, a1, x3);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(a3, c2, a1, x3)]);
    sort_indices<2,0,1,3,0,1,1,1>(i1data, i1data_sorted, a3.size(), c2.size(), a1.size(), x3.size());
    dgemm_("T", "N", x2.size(), a3.size()*c2.size()*x3.size(), a1.size(),
           1.0, i0data_sorted, a1.size(), i1data_sorted, a1.size(),
           1.0, odata_sorted, x2.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, x2.size(), a3.size(), c2.size(), x3.size());
  out()->put_block(odata, a3, c2, x3, x2);
}

void Task1470::Task_local::compute() {
  const Index a3 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x3 = b(3);
  // tensor label: I1842
  std::unique_ptr<double[]> odata = out()->move_block(a3, c2, a1, x3);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a1, c2, a3);
    sort_indices<3,2,1,0,1,1,-1,4>(i0data, odata, x3.size(), a1.size(), c2.size(), a3.size());
  }
  out()->put_block(odata, a3, c2, a1, x3);
}

void Task1471::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c2 : *range_[0]) {
    for (auto& a1 : *range_[2]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c2, a1, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c2, a1, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c2.size(), a1.size(), x0.size(), x1.size());
      // tensor label: I1853
      std::unique_ptr<double[]> i1data = in(1)->get_block(c2, a1, x3, x2);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(c2, a1, x3, x2)]);
      sort_indices<0,1,2,3,0,1,1,1>(i1data, i1data_sorted, c2.size(), a1.size(), x3.size(), x2.size());
      dgemm_("T", "N", x0.size()*x1.size(), x3.size()*x2.size(), c2.size()*a1.size(),
             1.0, i0data_sorted, c2.size()*a1.size(), i1data_sorted, c2.size()*a1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,2,3,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x3.size(), x2.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1472::Task_local::compute() {
  const Index c2 = b(0);
  const Index a1 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1853
  std::unique_ptr<double[]> odata = out()->move_block(c2, a1, x3, x2);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a1, c2, x2);
    dscal_(x2.size()*c2.size()*a1.size()*x3.size(), e0_, i0data.get(), 1);
    sort_indices<2,1,0,3,1,1,1,4>(i0data, odata, x3.size(), a1.size(), c2.size(), x2.size());
  }
  out()->put_block(odata, c2, a1, x3, x2);
}

void Task1473::Task_local::compute() {
  const Index c2 = b(0);
  const Index a1 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1853
  std::unique_ptr<double[]> odata = out()->move_block(c2, a1, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(c2, a1, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(c2, a1, x3, x2), 0.0);
  for (auto& a3 : *range_[2]) {
    // tensor label: f1
    std::unique_ptr<double[]> i0data = in(0)->get_block(x2, a3);
    std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x2, a3)]);
    sort_indices<1,0,0,1,1,1>(i0data, i0data_sorted, x2.size(), a3.size());
    // tensor label: I1854
    std::unique_ptr<double[]> i1data = in(1)->get_block(a3, c2, a1, x3);
    std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(a3, c2, a1, x3)]);
    sort_indices<0,1,2,3,0,1,1,1>(i1data, i1data_sorted, a3.size(), c2.size(), a1.size(), x3.size());
    dgemm_("T", "N", x2.size(), c2.size()*a1.size()*x3.size(), a3.size(),
           1.0, i0data_sorted, a3.size(), i1data_sorted, a3.size(),
           1.0, odata_sorted, x2.size());
  }
  sort_indices<1,2,3,0,1,1,1,1>(odata_sorted, odata, x2.size(), c2.size(), a1.size(), x3.size());
  out()->put_block(odata, c2, a1, x3, x2);
}

void Task1474::Task_local::compute() {
  const Index a3 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x3 = b(3);
  // tensor label: I1854
  std::unique_ptr<double[]> odata = out()->move_block(a3, c2, a1, x3);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a1, c2, a3);
    sort_indices<3,2,1,0,1,1,-1,4>(i0data, odata, x3.size(), a1.size(), c2.size(), a3.size());
  }
  out()->put_block(odata, a3, c2, a1, x3);
}

void Task1475::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a2, c1, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x3, a2, c1, x2)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x3.size(), a2.size(), c1.size(), x2.size());
      // tensor label: I1940
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, a2, c1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), a2.size(), c1.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1476::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1940
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
    dscal_(x1.size()*x0.size()*a2.size()*c1.size(), e0_, i0data.get(), 1);
    sort_indices<3,2,1,0,1,1,1,4>(i0data, odata, c1.size(), a2.size(), x0.size(), x1.size());
  }
  out()->put_block(odata, x1, x0, a2, c1);
}

void Task1477::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a2, x3, x2)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a2.size(), x3.size(), x2.size());
      // tensor label: I1943
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, a2, c1)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), a2.size(), c1.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1478::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1943
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
    dscal_(x1.size()*x0.size()*a2.size()*c1.size(), e0_, i0data.get(), 1);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, c1.size(), a2.size(), x0.size(), x1.size());
  }
  out()->put_block(odata, x1, x0, a2, c1);
}

void Task1479::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a2, c1, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a2, c1, x1)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a2.size(), c1.size(), x1.size());
      // tensor label: I1976
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1480::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1976
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    dscal_(x2.size()*x3.size()*a2.size()*c1.size(), e0_, i0data.get(), 1);
    sort_indices<3,2,1,0,1,1,1,4>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1481::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: t2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a2, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a2.size(), x0.size(), x1.size());
      // tensor label: I1979
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1482::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I1979
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    dscal_(x2.size()*x3.size()*a2.size()*c1.size(), e0_, i0data.get(), 1);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1483::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c2 : *range_[0]) {
    for (auto& a1 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c2, a1, x3, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c2, a1, x3, x2)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c2.size(), a1.size(), x3.size(), x2.size());
      // tensor label: I2009
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, c2, a1, x0);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, c2, a1, x0)]);
      sort_indices<1,2,0,3,0,1,1,1>(i1data, i1data_sorted, x1.size(), c2.size(), a1.size(), x0.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), c2.size()*a1.size(),
             1.0, i0data_sorted, c2.size()*a1.size(), i1data_sorted, c2.size()*a1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1484::Task_local::compute() {
  const Index x1 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x0 = b(3);
  // tensor label: I2009
  std::unique_ptr<double[]> odata = out()->move_block(x1, c2, a1, x0);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a1, c2, x1);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, x0.size(), a1.size(), c2.size(), x1.size());
  }
  out()->put_block(odata, x1, c2, a1, x0);
}

void Task1485::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c2 : *range_[0]) {
    for (auto& a1 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x3, x2, c2, a1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x3, x2, c2, a1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i0data, i0data_sorted, x3.size(), x2.size(), c2.size(), a1.size());
      // tensor label: I2018
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, c2, a1, x0);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, c2, a1, x0)]);
      sort_indices<1,2,0,3,0,1,1,1>(i1data, i1data_sorted, x1.size(), c2.size(), a1.size(), x0.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), c2.size()*a1.size(),
             1.0, i0data_sorted, c2.size()*a1.size(), i1data_sorted, c2.size()*a1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1486::Task_local::compute() {
  const Index x1 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x0 = b(3);
  // tensor label: I2018
  std::unique_ptr<double[]> odata = out()->move_block(x1, c2, a1, x0);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a1, c2, x1);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, x0.size(), a1.size(), c2.size(), x1.size());
  }
  out()->put_block(odata, x1, c2, a1, x0);
}

void Task1487::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a2, x3, x2)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a2.size(), x3.size(), x2.size());
      // tensor label: I2021
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, a2, c1)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), a2.size(), c1.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1488::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I2021
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
    sort_indices<3,2,1,0,1,1,1,1>(i0data, odata, c1.size(), a2.size(), x0.size(), x1.size());
  }
  out()->put_block(odata, x1, x0, a2, c1);
}

void Task1489::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a2, c1, x2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x3, a2, c1, x2)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x3.size(), a2.size(), c1.size(), x2.size());
      // tensor label: I2027
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, a2, c1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), a2.size(), c1.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1490::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I2027
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, c1.size(), a2.size(), x0.size(), x1.size());
  }
  out()->put_block(odata, x1, x0, a2, c1);
}

void Task1491::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x3, x2, c1, a2);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x3, x2, c1, a2)]);
      sort_indices<2,3,0,1,0,1,1,1>(i0data, i0data_sorted, x3.size(), x2.size(), c1.size(), a2.size());
      // tensor label: I2030
      std::unique_ptr<double[]> i1data = in(1)->get_block(x1, x0, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x1, x0, a2, c1)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x1.size(), x0.size(), a2.size(), c1.size());
      dgemm_("T", "N", x3.size()*x2.size(), x1.size()*x0.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x3.size()*x2.size());
    }
  }
  sort_indices<2,3,0,1,1,1,1,1>(odata_sorted, odata, x3.size(), x2.size(), x1.size(), x0.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1492::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I2030
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
    sort_indices<3,2,1,0,1,1,1,1>(i0data, odata, c1.size(), a2.size(), x0.size(), x1.size());
  }
  out()->put_block(odata, x1, x0, a2, c1);
}

void Task1493::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c2 : *range_[0]) {
    for (auto& a1 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c2, a1, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c2, a1, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c2.size(), a1.size(), x0.size(), x1.size());
      // tensor label: I2063
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, c2, a1, x3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, c2, a1, x3)]);
      sort_indices<1,2,0,3,0,1,1,1>(i1data, i1data_sorted, x2.size(), c2.size(), a1.size(), x3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), c2.size()*a1.size(),
             1.0, i0data_sorted, c2.size()*a1.size(), i1data_sorted, c2.size()*a1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1494::Task_local::compute() {
  const Index x2 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x3 = b(3);
  // tensor label: I2063
  std::unique_ptr<double[]> odata = out()->move_block(x2, c2, a1, x3);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a1, c2, x2);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, x3.size(), a1.size(), c2.size(), x2.size());
  }
  out()->put_block(odata, x2, c2, a1, x3);
}

void Task1495::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c2 : *range_[0]) {
    for (auto& a1 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, x1, c2, a1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, x1, c2, a1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i0data, i0data_sorted, x0.size(), x1.size(), c2.size(), a1.size());
      // tensor label: I2072
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, c2, a1, x3);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, c2, a1, x3)]);
      sort_indices<1,2,0,3,0,1,1,1>(i1data, i1data_sorted, x2.size(), c2.size(), a1.size(), x3.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), c2.size()*a1.size(),
             1.0, i0data_sorted, c2.size()*a1.size(), i1data_sorted, c2.size()*a1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1496::Task_local::compute() {
  const Index x2 = b(0);
  const Index c2 = b(1);
  const Index a1 = b(2);
  const Index x3 = b(3);
  // tensor label: I2072
  std::unique_ptr<double[]> odata = out()->move_block(x2, c2, a1, x3);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(x3, a1, c2, x2);
    sort_indices<3,2,1,0,1,1,-1,2>(i0data, odata, x3.size(), a1.size(), c2.size(), x2.size());
  }
  out()->put_block(odata, x2, c2, a1, x3);
}

void Task1497::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& c1 : *range_[0]) {
    for (auto& a2 : *range_[2]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x0, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(c1, a2, x0, x1)]);
      sort_indices<0,1,2,3,0,1,1,1>(i0data, i0data_sorted, c1.size(), a2.size(), x0.size(), x1.size());
      // tensor label: I2075
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
      sort_indices<3,2,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

void Task1498::Task_local::compute() {
  const Index x2 = b(0);
  const Index x3 = b(1);
  const Index a2 = b(2);
  const Index c1 = b(3);
  // tensor label: I2075
  std::unique_ptr<double[]> odata = out()->move_block(x2, x3, a2, c1);
  {
    // tensor label: t2
    std::unique_ptr<double[]> i0data = in(0)->get_block(c1, a2, x3, x2);
    sort_indices<3,2,1,0,1,1,1,1>(i0data, odata, c1.size(), a2.size(), x3.size(), x2.size());
  }
  out()->put_block(odata, x2, x3, a2, c1);
}

void Task1499::Task_local::compute() {
  const Index x1 = b(0);
  const Index x0 = b(1);
  const Index x3 = b(2);
  const Index x2 = b(3);
  // tensor label: I1331
  std::unique_ptr<double[]> odata = out()->move_block(x1, x0, x3, x2);
  std::unique_ptr<double[]> odata_sorted(new double[out()->get_size(x1, x0, x3, x2)]);
  std::fill_n(odata_sorted.get(), out()->get_size(x1, x0, x3, x2), 0.0);
  for (auto& a2 : *range_[2]) {
    for (auto& c1 : *range_[0]) {
      // tensor label: v2
      std::unique_ptr<double[]> i0data = in(0)->get_block(x0, a2, c1, x1);
      std::unique_ptr<double[]> i0data_sorted(new double[in(0)->get_size(x0, a2, c1, x1)]);
      sort_indices<1,2,0,3,0,1,1,1>(i0data, i0data_sorted, x0.size(), a2.size(), c1.size(), x1.size());
      // tensor label: I2081
      std::unique_ptr<double[]> i1data = in(1)->get_block(x2, x3, a2, c1);
      std::unique_ptr<double[]> i1data_sorted(new double[in(1)->get_size(x2, x3, a2, c1)]);
      sort_indices<2,3,0,1,0,1,1,1>(i1data, i1data_sorted, x2.size(), x3.size(), a2.size(), c1.size());
      dgemm_("T", "N", x0.size()*x1.size(), x2.size()*x3.size(), a2.size()*c1.size(),
             1.0, i0data_sorted, a2.size()*c1.size(), i1data_sorted, a2.size()*c1.size(),
             1.0, odata_sorted, x0.size()*x1.size());
    }
  }
  sort_indices<1,0,3,2,1,1,1,1>(odata_sorted, odata, x0.size(), x1.size(), x2.size(), x3.size());
  out()->put_block(odata, x1, x0, x3, x2);
}

