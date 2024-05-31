#include "game/core/game_runner.h"

namespace magic_loop {

GameRunner::GameRunner() {
  env_ = std::make_unique<Env>();
  env_->game_rule = std::make_unique<GameRule>();
}

}
