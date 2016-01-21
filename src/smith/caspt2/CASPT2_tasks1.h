//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: CASPT2_tasks1.h
// Copyright (C) 2014 Toru Shiozaki
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

#include <bagel_config.h>
#ifdef COMPILE_SMITH

#ifndef __SRC_SMITH_CASPT2_TASKS1_H
#define __SRC_SMITH_CASPT2_TASKS1_H

#include <src/smith/indexrange.h>
#include <src/smith/tensor.h>
#include <src/smith/task.h>
#include <src/smith/subtask.h>
#include <src/smith/storage.h>

namespace bagel {
namespace SMITH {
namespace CASPT2{

class Task0 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,5> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,5>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,5>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task0" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task0(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task0() {}
};

class Task1 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task1" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task1(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task1() {}
};

class Task2 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task2" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task2(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task2() {}
};

class Task3 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task3" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task3(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task3() {}
};

class Task4 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task4" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task4(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task4() {}
};

class Task5 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<8,5> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,8>& block, const std::array<std::shared_ptr<const Tensor>,5>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<8,5>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task5" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task5(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task5() {}
};

class Task6 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task6" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task6(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task6() {}
};

class Task7 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task7" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task7(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task7() {}
};

class Task8 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task8" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task8(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task8() {}
};

class Task9 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task9" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task9(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task9() {}
};

class Task10 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task10" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task10(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task10() {}
};

class Task11 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<2,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task11" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task11(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task11() {}
};

class Task12 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task12" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task12(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task12() {}
};

class Task13 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task13" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task13(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task13() {}
};

class Task14 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task14" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task14(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task14() {}
};

class Task15 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task15" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task15(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task15() {}
};

class Task16 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task16" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task16(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task16() {}
};

class Task17 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task17" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task17(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task17() {}
};

class Task18 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task18" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task18(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task18() {}
};

class Task19 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task19" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task19(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task19() {}
};

class Task20 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<2,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,1>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task20" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task20(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task20() {}
};

class Task21 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task21" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task21(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task21() {}
};

class Task22 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task22" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task22(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task22() {}
};

class Task23 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task23" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task23(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task23() {}
};

class Task24 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<8,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,8>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<8,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task24" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task24(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task24() {}
};

class Task25 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task25" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task25(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task25() {}
};

class Task26 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task26" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task26(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task26() {}
};

class Task27 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task27" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task27(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task27() {}
};

class Task28 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task28" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task28(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task28() {}
};

class Task29 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task29" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task29(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task29() {}
};

class Task30 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task30" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task30(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task30() {}
};

class Task31 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task31" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task31(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task31() {}
};

class Task32 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task32" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task32(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task32() {}
};

class Task33 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<6,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,1>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task33" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task33(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task33() {}
};

class Task34 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<8,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,8>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<8,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task34" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task34(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task34() {}
};

class Task35 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<8,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,8>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<8,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task35" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task35(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task35() {}
};

class Task36 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<4,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task36" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task36(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task36() {}
};

class Task37 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<7,5> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,7>& block, const std::array<std::shared_ptr<const Tensor>,5>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<7,5>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task37" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task37(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task37() {}
};

class Task38 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task38" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task38(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task38() {}
};

class Task39 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<7,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,7>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<7,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task39" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task39(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task39() {}
};

class Task40 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task40" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task40(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task40() {}
};

class Task41 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<7,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,7>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<7,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task41" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task41(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task41() {}
};

class Task42 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<9,5> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,9>& block, const std::array<std::shared_ptr<const Tensor>,5>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<9,5>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task42" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task42(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task42() {}
};

class Task43 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<7,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,7>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<7,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task43" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task43(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task43() {}
};

class Task44 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task44" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task44(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task44() {}
};

class Task45 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<7,3> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,7>& block, const std::array<std::shared_ptr<const Tensor>,3>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<7,3>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task45" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task45(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task45() {}
};

class Task46 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task46" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task46(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task46() {}
};

class Task47 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,4> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,4>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,4>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task47" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task47(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task47() {}
};

class Task48 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<3,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,3>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<3,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task48" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task48(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task48() {}
};

class Task49 : public Task {  // associated with gamma
  protected:
    class Task_local : public SubTask<5,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,4> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
      public:
        Task_local(const std::array<const Index,5>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,4>& ran)
          : SubTask<5,2>(block, in, out), range_(ran) { }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
std::cout << "Task49" << std::endl;
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task49(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,4> range);
    ~Task49() {}
};


}
}
}
#endif
#endif

