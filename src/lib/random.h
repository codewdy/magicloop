#pragma once

#include <random>

namespace magic_loop {

struct Random {
  std::mt19937 thread_local_rnd_init() {
    return std::mt19937(std::random_device()());
  }
  std::mt19937& thread_local_rnd() {
    static thread_local std::mt19937 rnd = thread_local_rnd();
    return rnd;
  }
  int randint(int e) {
    return randint(0, e);
  }
  int randint(int b, int e) {
    return thread_local_rnd()() % (e - b) + b;
  }
};

}
