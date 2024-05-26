#pragma once

namespace magic_loop {

class Env;

class BattleRunner {
 public:
  struct Args {
    // Map
    // Level
    // Player
    Env* env;
  };
  explicit BattleRunner(Args args);

  void run();
  void move();
  void update();

 private:
  Env* env_;
};

}
