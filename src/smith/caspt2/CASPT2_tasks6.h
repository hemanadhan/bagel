//
// BAGEL - Brilliantly Advanced General Electronic Structure Library
// Filename: CASPT2_tasks6.h
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

#ifndef __SRC_SMITH_CASPT2_TASKS6_H
#define __SRC_SMITH_CASPT2_TASKS6_H

#include <src/smith/indexrange.h>
#include <src/smith/tensor.h>
#include <src/smith/task.h>
#include <src/smith/subtask.h>
#include <src/smith/storage.h>

namespace bagel {
namespace SMITH {
namespace CASPT2{

class Task250 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task250" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task250(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task250() {}
};

class Task251 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task251" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task251(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task251() {}
};

class Task252 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task252" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task252(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task252() {}
};

class Task253 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task253" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task253(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task253() {}
};

class Task254 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task254" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task254(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task254() {}
};

class Task255 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task255" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task255(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task255() {}
};

class Task256 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task256" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task256(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task256() {}
};

class Task257 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task257" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task257(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task257() {}
};

class Task258 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task258" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task258(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task258() {}
};

class Task259 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task259" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task259(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task259() {}
};

class Task260 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task260" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task260(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task260() {}
};

class Task261 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task261" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task261(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task261() {}
};

class Task262 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task262(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task262() {}
};

class Task263 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task263(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task263() {}
};

class Task264 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task264(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task264() {}
};

class Task265 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task265(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task265() {}
};

class Task266 : public AccTask {
  protected:
    class Task_local : public SubTask<2,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task266(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task266() {}
};

class Task267 : public AccTask {
  protected:
    class Task_local : public SubTask<2,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task267(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task267() {}
};

class Task268 : public AccTask {
  protected:
    class Task_local : public SubTask<2,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task268(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task268() {}
};

class Task269 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task269(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task269() {}
};

class Task270 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task270(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task270() {}
};

class Task271 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task271(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task271() {}
};

class Task272 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task272(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task272() {}
};

class Task273 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task273(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task273() {}
};

class Task274 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task274(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task274() {}
};

class Task275 : public AccTask {
  protected:
    class Task_local : public SubTask<6,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task275(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task275() {}
};

class Task276 : public AccTask {
  protected:
    class Task_local : public SubTask<6,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,6>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<6,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task276(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task276() {}
};

class Task277 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task277(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task277() {}
};

class Task278 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task278(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task278() {}
};

class Task279 : public AccTask {
  protected:
    class Task_local : public SubTask<2,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task279(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task279() {}
};

class Task280 : public AccTask {
  protected:
    class Task_local : public SubTask<2,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task280(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task280() {}
};

class Task281 : public AccTask {
  protected:
    class Task_local : public SubTask<2,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,2>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<2,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task281(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task281() {}
};

class Task282 : public AccTask {
  protected:
    class Task_local : public SubTask<4,2> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,2>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,2>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task282(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task282() {}
};

class Task283 : public AccTask {
  protected:
    class Task_local : public SubTask<4,1> {
      protected:
        const std::array<std::shared_ptr<const IndexRange>,3> range_;
        const Index& b(const size_t& i) const { return this->block(i); }
        std::shared_ptr<const Tensor> in(const size_t& i) const { return this->in_tensor(i); }
        std::shared_ptr<Tensor> out() { return this->out_tensor(); }
        double target_;
      public:
        Task_local(const std::array<const Index,4>& block, const std::array<std::shared_ptr<const Tensor>,1>& in, std::shared_ptr<Tensor>& out,
                   std::array<std::shared_ptr<const IndexRange>,3>& ran)
          : SubTask<4,1>(block, in, out), range_(ran) { }
        double target() const { return detail::real(target_); }
        void compute() override;
    };
    std::vector<std::shared_ptr<Task_local>> subtasks_;
    void compute_() override {
      auto out = subtasks_.front()->out_tensor();
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      this->target_ = 0.0;
      for (auto& i : subtasks_) {
        i->compute();
        this->target_ += i->target();
      }
    }
  public:
    Task283(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task283() {}
};

class Task284 : public Task {
  protected:
    std::shared_ptr<Tensor> den2_;
    IndexRange closed_;
    IndexRange active_;
    IndexRange virt_;
    const bool reset_;
    void compute_() {
      if (reset_) den2_->zero();
    }
  public:
    Task284(std::vector<std::shared_ptr<Tensor>> t, const bool reset);
    ~Task284() {}
};

class Task285 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task285" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task285(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task285() {}
};

class Task286 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task286" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task286(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task286() {}
};

class Task287 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task287" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task287(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task287() {}
};

class Task288 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task288" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task288(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task288() {}
};

class Task289 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task289" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task289(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task289() {}
};

class Task290 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task290" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task290(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task290() {}
};

class Task291 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task291" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task291(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task291() {}
};

class Task292 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task292" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task292(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task292() {}
};

class Task293 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task293" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task293(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task293() {}
};

class Task294 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task294" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task294(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task294() {}
};

class Task295 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task295" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task295(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task295() {}
};

class Task296 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task296" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task296(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task296() {}
};

class Task297 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task297" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task297(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task297() {}
};

class Task298 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task298" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task298(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task298() {}
};

class Task299 : public Task {
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
      auto out = subtasks_.front()->out_tensor();
std::cout << "Task299" << std::endl;
      if (!out->allocated())
        out->allocate();
      for (auto& i : subtasks_.front()->in_tensors())
        i->init();
      for (auto& i : subtasks_) i->compute();
    }
  public:
    Task299(std::vector<std::shared_ptr<Tensor>> t, std::array<std::shared_ptr<const IndexRange>,3> range);
    ~Task299() {}
};


}
}
}
#endif
#endif

