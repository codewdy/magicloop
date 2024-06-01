#pragma once

#include <memory>
#include <vector>
#include "game/core/map_template.h"

namespace magic_loop {

struct Env;

class MapCreator {
 public:
  explicit MapCreator(Env* env);
  void register_map_template(std::unique_ptr<MapTempalte> mt);
  void create();

 private:
  Env* env_;
  std::vector<std::unique_ptr<MapTempalte>> mts_;
};

}

