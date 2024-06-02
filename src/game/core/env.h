#pragma once

#include <memory>

#include "game/core/battle_runner.h"
#include "game/core/unit_collection.h"
#include "game/core/game_rule.h"
#include "game/core/map.h"
#include "game/core/map_creator.h"
#include "game/core/player.h"
#include "game/core/ui.h"

namespace magic_loop {

struct Env {
  std::unique_ptr<GameRule> game_rule;
  std::unique_ptr<MapCreator> map_creator;
  std::shared_ptr<UI> ui;
  std::unique_ptr<BattleRunner> battle;
  Ref<Player> player;
  Ref<Map> map;
  std::unique_ptr<UnitCollection> units;
};

}
