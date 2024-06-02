#pragma once

#include "game/core/renderable.h"

namespace magic_loop {

class Map : public Renderable {
 public:
  std::string render_name() override { return "Map"; }

  void init(const std::string& name) {
    name_ = name;
  }

  std::string name() {
    return name_;
  }

 private:
  std::string name_;
};

}
