#pragma once

namespace magic_loop {

struct GameRule {
  int tick_time_ms = 16;
  int update_per_tick = 2;
  float width = 100;
  float height = 100;
};

}
