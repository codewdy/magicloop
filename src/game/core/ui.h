#pragma once

#include "game/core/renderable.h"

namespace magic_loop {
class UI {
 public:
  virtual ~UI() = default;
  virtual void start_battle() = 0;
  virtual void add_render(Ref<Renderable> renderable) = 0;
  virtual void kill() = 0;
};

}

