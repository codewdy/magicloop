#pragma once

#include "game/core/element.h"

namespace magic_loop {

struct ElementVec {
  float& operator[](int e) { return vec[e]; }
  const float& operator[](int e) const { return vec[e]; }
  float vec[kElementSize];
};

using Damage = ElementVec;
using DamageFactor = ElementVec;

}
