#pragma once

#include <memory>
#include "game/core/map_template.h"

namespace magic_loop {

class Env;

class MapCreator {
 public:
  MapCreator(Env* env);
  void register_map_template(std::unique_ptr<MapTempalte>);
  void create_map();

 private:
  Env* env_;
};

}

