#include "game/core/game_runner.h"
#include <iostream>

using namespace magic_loop;

class MockUI : public UI {
 public:
  void add_render(Ref<Renderable> renderable) override {
    std::cout << "render " << renderable->render_name() << std::endl;
  }
  void kill() override {
    std::cout << "kill" << std::endl;
  }
};

int main() {
  auto mock_ui = std::make_shared<MockUI>();
  GameRunner game;
  game.set_ui(mock_ui);
  game.register_map_template(std::make_unique<MapTempalte>("234"));
  for (int i = 0; i < 20; i++) {
    std::cout << "Update " << i << std::endl;
    game.update();
  }
}
