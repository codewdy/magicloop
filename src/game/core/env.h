#pragma once

#include <memory>

#include "game/core/battle_runner.h"
#include "game/core/unit_collection.h"
#include "game/core/game_rule.h"

namespace magic_loop {

class Env {
 public:
  GameRule* game_rule() { return game_rule_.get(); }
 private:
  std::unique_ptr<GameRule> game_rule_;
  std::unique_ptr<BattleRunner> battle_;
  std::unique_ptr<UnitCollection> units_;
};

}
