#include "game/core/game_runner.h"

namespace magic_loop {

GameRunner::GameRunner() {
  updater_.reset(new Generator<int>(main_loop()));
  env_ = std::make_unique<Env>();
  env_->game_rule = std::make_unique<GameRule>();
  env_->map_creator = std::make_unique<MapCreator>(env_.get());
  env_->player = create_object<Player>(env_.get());
}

GameRule* GameRunner::game_rule() {
  return env_->game_rule.get();
}

void GameRunner::register_map_template(std::unique_ptr<MapTempalte> mt) {
  env_->map_creator->register_map_template(std::move(mt));
}

void GameRunner::set_ui(std::shared_ptr<UI> ui) {
  env_->ui = ui;
}

void GameRunner::update() {
  int x = (*updater_)();
}

Generator<int> GameRunner::main_loop() {
  while (true) {
    for (int i = 0; i < env_->game_rule->start_battle_tick; i++) {
      co_yield 0;
    }
    env_->battle.reset(new BattleRunner(env_.get()));
    env_->battle->init();
    co_yield 0;
    while (true) {
      env_->battle->update();
      co_yield 0;
    }
  }
}

}
