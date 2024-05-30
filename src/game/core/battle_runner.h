#pragma once

namespace magic_loop {

class Env;

class BattleRunner {
 public:
  explicit BattleRunner(Env* env);

  void init();
  void clear();

  void run();
  void move();
  void update();

 private:
  Env* env_;
};

}
