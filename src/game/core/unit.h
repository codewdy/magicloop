#pragma once

#include "game/core/damage.h"
#include "game/core/renderable.h"

namespace magic_loop {

struct Env;

class Unit : public Renderable {
 public:
  std::string render_name() override { return "Unit"; }

  void init(Env* env) {
    env_ = env;
  }

  void update();
  void move();
  Damage calc_damage(Damage dmg);
  void damage(Damage dmg);

  void on_update();
  void on_struct(Unit* src);
  void on_hit(Unit* dst);
  void on_death(Unit* src);
  void on_kill(Unit* dst);
  void on_damage_pre(Damage* dmg);
  void on_damage_post(Damage* dmg);

 private:
  Env* env_;
  DamageFactor src_damage_convert_[kElementSize];
  DamageFactor src_damage_incr_;
  DamageFactor src_damage_more_;
  DamageFactor dst_damage_convert_[kElementSize];
  DamageFactor damage_resistance_;
  DamageFactor damage_flat_resistance_;
};

}
