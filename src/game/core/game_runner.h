#pragma once

#include "game/core/env.h"

namespace magic_loop {

class GameRunner {
 public:
  GameRunner();
  GameRule* game_rule();
  void register_map_template(std::unique_ptr<MapTempalte>);
 private:
  std::unique_ptr<Env> env_;
};

}
