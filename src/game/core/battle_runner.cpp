#include "game/core/battle_runner.h"
#include "game/core/env.h"

namespace magic_loop {

BattleRunner::BattleRunner(Env* env) {
  env_ = env;
}

void BattleRunner::init() {
  env_->map_creator->create();
  env_->ui->add_render(env_->map);
  add_unit(env_->player);
}

void BattleRunner::clear() {
  env_->map = nullptr;
  env_->units = nullptr;
}

void BattleRunner::run() {
}

void BattleRunner::move() {
}

void BattleRunner::update() {
}

void BattleRunner::add_unit(Ref<Unit> unit) {
  env_->ui->add_render(unit);
}

}
