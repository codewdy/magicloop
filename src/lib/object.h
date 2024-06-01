#pragma once

#include <type_traits>
#include <utility>
#include <memory>
#include <vector>

namespace magic_loop {

class Object {
 public:
  using ObjectRecycleFunc = void(Object*);
  using ObjectRecycleFuncPtr = ObjectRecycleFunc*;

  virtual ~Object() = default;

  void start(ObjectRecycleFuncPtr recycle) {
    ref_count_ = 0;
    recycle_ = recycle;
  }
  void ref() {
    ref_count_++;
  }
  void unref() {
    if (--ref_count_ == 0) {
      recycle_(this);
    }
  }
 private:
  int ref_count_;
  ObjectRecycleFuncPtr recycle_;
};

template<typename T,
         typename Tok = std::enable_if_t<std::is_convertible_v<T*, Object*>>>
class Ref {
 public:
  Ref() {
    raw_ = nullptr;
  }
  Ref(T* rhs) {
    raw_ = rhs;
    raw_->ref();
  }
  ~Ref() {
    if (raw_) {
      raw_->unref();
    }
  }
  template<typename U, typename Uok = std::enable_if_t<std::is_convertible_v<U*, T*>>>
  Ref(const Ref<U>& rhs) {
    raw_ = rhs.raw_;
    raw_->ref();
  }

  template<typename U, typename Uok = std::enable_if_t<std::is_convertible_v<U*, T*>>>
  Ref(Ref<U>&& rhs) {
    raw_ = rhs.raw_;
    rhs.raw_ = nullptr;
  }

  template<typename U, typename Uok = std::enable_if_t<std::is_convertible_v<U*, T*>>>
  Ref& operator=(const Ref<U>& rhs) {
    if (raw_) {
      raw_->unref();
    }
    raw_ = rhs.raw_;
    raw_->ref();
  }

  template<typename U, typename Uok = std::enable_if_t<std::is_convertible_v<U*, T*>>>
  Ref& operator=(Ref<U>&& rhs) {
    if (raw_) {
      raw_->unref();
    }
    raw_ = rhs.raw_;
    rhs.raw_ = nullptr;
  }

  T& operator*() const {
    return *raw_;
  }

  T* operator->() const {
    return raw_;
  }
 private:
  T* raw_;
};

template<typename T>
class ObjectPool {
 public:
  static void recycle(Object* o) {
    State* s = state();
    s->pool_.push_back((T*)o);
  }
  template<typename... Targs>
  static Ref<T> create(Targs&&... args) {
    State* s = state();
    if (s->pool_.empty()) {
      s->mem_.emplace_back(new T[kBlock]);
      for (int i = 0; i < kBlock; i++) {
        s->pool_.push_back(s->mem_.back().get() + i);
      }
    }
    T* x = s->pool_.back();
    s->pool_.pop_back();
    x->start(recycle);
    x->init(std::forward<Targs>(args)...);
    return Ref<T>(x);
  }
 private:
  static constexpr int kBlock = 64;
  struct State {
    std::vector<std::unique_ptr<T[]>> mem_;
    std::vector<T*> pool_;
  };
  static State* state() {
    static State instance;
    return &instance;
  }
};

template<typename T, typename... Targs>
Ref<T> create_object(Targs&&... args) {
  return ObjectPool<T>::create(std::forward<Targs>(args)...);
}

}
