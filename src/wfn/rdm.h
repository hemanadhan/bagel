//
// BAGEL - Parallel electron correlation program.
// Filename: rdm.h
// Copyright (C) 2011 Toru Shiozaki
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


#ifndef __BAGEL_WFN_RDM_H
#define __BAGEL_WFN_RDM_H

#include <type_traits>
#include <src/wfn/geometry.h>

namespace bagel {


template <int rank, typename DataType = double>
class RDM : public btas::TensorN<DataType, rank*2> {
  private:
    constexpr const static int N = rank*2;
  public:
    using btas::TensorN<DataType, N>::data;
    using btas::TensorN<DataType, N>::begin;
    using btas::TensorN<DataType, N>::end;
    using btas::TensorN<DataType, N>::cbegin;
    using btas::TensorN<DataType, N>::cend;

  private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int) {
// TODO
    }

  public:
    RDM() { }

    RDM(const int n) : btas::TensorN<DataType, N>(btas::CRange<N>(btas::Range1(n),N)) {
      zero();
    }

    RDM(const RDM<rank,DataType>& o) : btas::TensorN<DataType, N>(o) {
    }

    RDM(RDM<rank,DataType>&& o) : btas::TensorN<DataType, N>(std::move(o)) {
    }

    std::shared_ptr<RDM<rank,DataType>> clone() const { return std::make_shared<RDM<rank,DataType>>(this->norb()); }
    std::shared_ptr<RDM<rank,DataType>> copy() const { return std::make_shared<RDM<rank,DataType>>(*this); }

    template<typename ...args>
    DataType& element(const args&... index) { return (*this)(index...); }

    template<typename ...args>
    const DataType& element(const args&... index) const { return (*this)(index...); }

    RDM<rank,DataType>& operator+=(const RDM<rank,DataType>& o) { this->ax_plus_y(1.0, o); return *this; }
    RDM<rank,DataType>& operator-=(const RDM<rank,DataType>& o) { this->ax_plus_y(-1.0, o); return *this; }
    RDM<rank,DataType> operator+(const RDM<rank,DataType>& o) const { RDM<rank,DataType> out(*this); out += o; return out; }
    RDM<rank,DataType> operator-(const RDM<rank,DataType>& o) const { RDM<rank,DataType> out(*this); out -= o; return out; }

    void zero() { this->fill(0.0); }

    void ax_plus_y(const DataType a, const btas::TensorN<DataType,N>& o) { btas::axpy(a, o, *this); }
    void ax_plus_y(const DataType& a, const std::shared_ptr<const btas::TensorN<DataType,N>>& o) { this->ax_plus_y(a, *o); }

    void scale(const DataType& a) { btas::scal(a, *this); }
    size_t size() const { return this->storage().size(); }
    int norb() const { return this->extent(0); }

    // returns if this is natural orbitals - only for rank 1
    bool natural_orbitals() const {
      throw std::logic_error("RDM<N>::natural_orbitals() should not be called with N>1");
      return true;
    }

    std::shared_ptr<Matrix> rdm1_mat(const int nclosed, const bool all = true) const {
      throw std::logic_error("RDM<N>::rdm1_mat() should not be called with N>1");
      return nullptr;
    }

    std::pair<std::shared_ptr<Matrix>, VectorB> generate_natural_orbitals() const {
      throw std::logic_error("RDM<N>::generate_natural_orbitals() should not be called with N>1");
      return std::pair<std::shared_ptr<Matrix>, VectorB>();
    }

    void transform(const std::shared_ptr<Matrix>& coeff) { throw std::logic_error("RDM<N>::transform() (N>3) not implemented yet"); }

    std::vector<DataType> diag() const {
      throw std::logic_error("RDM<N>::diag() should not be called with N>1");
      return std::vector<DataType>();
    }

    template<typename T = DataType,
             class = typename std::enable_if<std::is_same<T,std::complex<double>>::value>::type
            >
    std::shared_ptr<RDM<rank,double>> get_real_part() const {
      auto out = std::make_shared<RDM<rank,double>>(norb());
      auto i = out->begin();
      for (auto& d : *this)
        *i++ = std::real(d);
      return out;
    }

    template<typename T = DataType,
             class = typename std::enable_if<std::is_same<T,std::complex<double>>::value>::type
            >
    std::shared_ptr<RDM<rank,double>> get_imag_part() const {
      auto out = std::make_shared<RDM<rank,double>>(norb());
      auto i = out->begin();
      for (auto& d : *this)
        *i++ = std::imag(d);
      return out;
    }

    void print(const double thresh = 1.0e-3) const { throw std::logic_error("RDM<N>::print() (N>3) not implemented yet"); }
};

template <int rank>
using ZRDM = RDM<rank, std::complex<double>>;

template<> bool RDM<1,double>::natural_orbitals() const;
template<> std::vector<double> RDM<1,double>::diag() const;

template<> std::pair<std::shared_ptr<Matrix>, VectorB> RDM<1,double>::generate_natural_orbitals() const;

template<> void RDM<1,double>::transform(const std::shared_ptr<Matrix>& coeff);
template<> void RDM<2,double>::transform(const std::shared_ptr<Matrix>& coeff);

template<> std::shared_ptr<Matrix> RDM<1,double>::rdm1_mat(const int nclosed, const bool all) const;

template<> void RDM<1,double>::print(const double thresh) const;
template<> void RDM<2,double>::print(const double thresh) const;
template<> void RDM<3,double>::print(const double thresh) const;

}

#endif
