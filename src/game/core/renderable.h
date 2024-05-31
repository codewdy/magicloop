#pragma once

#include <string>

#include "lib/object.h"

namespace magic_loop {

class Renderable : public Object {
 public:
  virtual std::string render_name() = 0;
 private:
};

}
