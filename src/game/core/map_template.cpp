#include "game/core/map_template.h"
#include "game/core/env.h"

namespace magic_loop {

MapTempalte::MapTempalte(std::string name) {
  name_ = name;
}

void MapTempalte::create(Env* env) {
  env->map = create_object<Map>(name_);
}

}
