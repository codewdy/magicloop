#pragma once

#include "game/core/env.h"

namespace magic_loop {

class GameRunner {
 public:
 private:
   std::unique_ptr<Env> env_;
};

}
