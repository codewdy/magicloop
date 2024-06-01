#pragma once

#include <functional>
#include <memory>
#include <ucontext.h>

namespace magic_loop {

namespace _generator_details {

class GeneratorBase {
 public:
  virtual ~GeneratorBase() = default;

  GeneratorBase() {
    end_ = false;
    getcontext(&gen_ctx_);
    gen_ctx_.uc_link = &main_ctx_;
    gen_ctx_.uc_stack.ss_sp = stack_;
    gen_ctx_.uc_stack.ss_size = sizeof(stack_);
    gen_ctx_.uc_stack.ss_flags = 0;
    makecontext(&gen_ctx_, (F*)&GeneratorBase::static_start, 1, this);
  }

 protected:

  bool end() { return end_; }

  bool run_next() {
    auto parent = current_generator_;
    swapcontext(&main_ctx_, &gen_ctx_);
    current_generator_ = parent;
    return !end();
  }

  static void yield() {
    auto self = current_generator_;
    swapcontext(&self->gen_ctx_, &self->main_ctx_);
    current_generator_ = self;
  }

  virtual void gen() = 0;

  void start() {
    current_generator_ = this;
    gen();
    end_ = true;
    current_generator_ = nullptr;
  }

  static void static_start(GeneratorBase* g) { g->start(); }
  typedef void F();
  ucontext_t main_ctx_, gen_ctx_;
  bool end_;
  char stack_[1024 * 32];

  static thread_local GeneratorBase* current_generator_;
};

template <typename T>
class GeneratorImpl : public GeneratorBase {
 public:
  GeneratorImpl(std::function<void()> func) {
    func_ = func;
  }
  void gen() {
    func_();
  }
  bool next(T& rst) {
    rst_ = &rst;
    return run_next();
  }
  template <typename... Targs>
  static void yield(Targs&&... args) {
    auto r = current_generator_;
    GeneratorImpl* self = dynamic_cast<GeneratorImpl*>(current_generator_);
    *self->rst_ = T(std::forward<Targs>(args)...);
    GeneratorBase::yield();
  }
 private:
  std::function<void()> func_;
  T* rst_;
};

}

template <typename T>
class Generator {
 public:
  Generator() = default;
  Generator(std::function<void()> func) {
    impl_.reset(new _generator_details::GeneratorImpl<T>(func));
  }
  bool next(T& rst) {
    return impl_->next(rst);
  }
  template <typename... Targs>
  static void yield(Targs&&... args) {
    _generator_details::GeneratorImpl<T>::yield(std::forward<Targs>(args)...);
  }
 private:
  std::unique_ptr<_generator_details::GeneratorImpl<T>> impl_;
};

}
