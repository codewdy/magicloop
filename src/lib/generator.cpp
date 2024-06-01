#include "lib/generator.h"

namespace magic_loop {

thread_local _generator_details::GeneratorBase*
  _generator_details::GeneratorBase::current_generator_;

}
