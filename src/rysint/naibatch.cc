//
// Newint - Parallel electron correlation program.
// Filename: naibatch.cc
// Copyright (C) 2009 Toru Shiozaki
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

#include <cmath>
#include <cassert>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <src/rysint/inline.h>
#include <src/rysint/naibatch.h>
#include <src/util/f77.h>
#include <src/rysint/f77.h>
#include <src/rysint/macros.h>
#include <src/stackmem.h>
#define PI 3.1415926535897932
#define SQRTPI2 0.886226925452758013649083741671

using namespace std;

typedef std::shared_ptr<Geometry> RefGeometry;
typedef std::shared_ptr<Atom> RefAtom;
typedef std::shared_ptr<Shell> RefShell;

extern StackMem* stack;

NAIBatch::NAIBatch(const vector<RefShell> _info, const shared_ptr<Geometry> gm, const int L, const double A)
 :  NAIBatch_base(_info, gm, 0, L, A) {

}


NAIBatch::~NAIBatch() {
}


