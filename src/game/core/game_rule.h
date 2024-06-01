#pragma once

namespace magic_loop {

struct GameRule {
  int tick_time_ms = 16;
  int update_per_tick = 2;
  int start_battle_tick = 10;
  float width = 100;
  float height = 100;
};

}
