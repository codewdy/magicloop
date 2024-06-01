#pragma once

#include "game/core/unit.h"

namespace magic_loop {

struct Env;

class BattleRunner {
 public:
  explicit BattleRunner(Env* env);

  void init();
  void clear();

  void run();
  void move();

  void update();

  void add_unit(Ref<Unit> unit);

 private:
  Env* env_;
};

}
