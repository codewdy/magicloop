#pragma once

#include "game/core/env.h"
#include "lib/generator.h"

namespace magic_loop {

class GameRunner {
 public:
  GameRunner();
  GameRule* game_rule();
  void register_map_template(std::unique_ptr<MapTempalte> mt);
  void update();
  void main_loop();

 private:
  std::unique_ptr<Env> env_;
  Generator<int> updater_;
};

}
