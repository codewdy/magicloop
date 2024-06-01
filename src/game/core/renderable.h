#pragma once

#include <string>

#include "lib/object.h"

namespace magic_loop {

class Renderable : public Object {
 public:
  virtual std::string render_name() = 0;
 private:
};

class RenderableManager {
 public:
  virtual ~RenderableManager() = default;
  virtual void add(Ref<Renderable> renderable) = 0;
  virtual void kill() = 0;
};

}
