#include "game/core/map_creator.h"
#include "lib/random.h"

namespace magic_loop {

MapCreator::MapCreator(Env* env) {
  env_ = env;
}

void MapCreator::register_map_template(std::unique_ptr<MapTempalte> mt) {
  mts_.push_back(std::move(mt));
}

void MapCreator::create() {
  MapTempalte* mt = mts_[Random::randint(mts_.size())].get();
  mt->create(env_);
}

}
