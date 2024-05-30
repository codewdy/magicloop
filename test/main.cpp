#include "lib/object.h"
#include <iostream>

using namespace magic_loop;
class XO : public Object {
 public:
  void Init(int x) {
    x_ = x;
  };
  int x_;
};

int main() {
  {
    auto x = create_object<XO>(1);
    std::cout << x->x_ << std::endl;
    std::cout << &*x << std::endl;
  }
  {
    auto x = create_object<XO>(1);
    std::cout << x->x_ << std::endl;
    std::cout << &*x << std::endl;
    auto y = create_object<XO>(2);
    std::cout << y->x_ << std::endl;
    std::cout << &*y << std::endl;
  }
}
