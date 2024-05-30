#pragma once

#include "game/core/vector2d.h"

namespace magic_loop {

class Map {
 public:
  void Move(Vector2D origin, Vector2D diff, float size,
      Vector2D* rst, bool* blocked);
};

}
