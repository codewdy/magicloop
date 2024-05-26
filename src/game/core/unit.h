#pragma once

#include "game/core/damage.h"

namespace magic_loop {

class Env;

class Unit {
 public:
  Unit(Env* env);

  Env* env();

  virtual void update();
  virtual void move();
  virtual Damage calc_damage(Damage dmg);
  virtual void damage(Damage dmg);

  virtual void on_update();
  virtual void on_struct(Unit* src);
  virtual void on_hit(Unit* dst);
  virtual void on_death(Unit* src);
  virtual void on_kill(Unit* dst);
  virtual void on_damage_pre(Damage* dmg);
  virtual void on_damage_post(Damage* dmg);

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
