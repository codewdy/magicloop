#pragma once

#include "game/core/renderable.h"

namespace magic_loop {

class Map : public Renderable {
 public:
  void init(const std::string& name);

  std::string name() {
    return name_;
  }

 private:
  std::string name_;
};

}
