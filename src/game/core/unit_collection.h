#pragma once

#include <vector>

#include "game/core/unit.h"

namespace magic_loop {

class UnitCollection {
 public:
  std::vector<Unit*> all_units();
 private:
};

}
