#pragma once

#include <string>

namespace magic_loop {

class Renderable {
 public:
  virtual std::string render_name() = 0;
 private:
};

}
