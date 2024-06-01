#pragma once

#include <string>

namespace magic_loop {

struct Env;

class MapTempalte {
 public:
  MapTempalte(std::string name);
  std::string name();
  void create(Env* env);

 private:
  std::string name_;
};

}
