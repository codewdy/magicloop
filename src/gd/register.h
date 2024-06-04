#pragma once

#include <functional>
#include <vector>

namespace magic_loop {

class GDRegister {
 public:

  static GDRegister* Instance() {
    static GDRegister instance;
    return &instance;
  }

  void Register(std::function<void()> func) {
    funcs_.emplace_back(func);
  }

  void Run() {
    for (auto&& func : funcs_) {
      func();
    }
  }
 private:
  std::vector<std::function<void()>> funcs_;
};

struct GDRegisterHelper {
  GDRegisterHelper(std::function<void()> func) {
    GDRegister::Instance()->Register(func);
  }
};

}

#define GDREGISTER_HELPER2(x, y) x##y
#define GDREGISTER_HELPER(x, y) GDREGISTER_HELPER2(x, y)
#define GDREGISTER(FUNC) static ::magic_loop::GDRegisterHelper \
  GDREGISTER_HELPER(GDREGISTERX_, __COUNTER__)([] FUNC);
