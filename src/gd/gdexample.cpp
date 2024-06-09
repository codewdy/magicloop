#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "gd/register.h"

using namespace godot;

void GDExample::_bind_methods() {
}

GDExample::GDExample() {
	// Initialize any variables here.
  UtilityFunctions::print("Start");
	time_passed = 0.0;
  xx = 1;
}

GDExample::~GDExample() {
  UtilityFunctions::print("Cleanup");
	// Add your cleanup here.
}

void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)) * xx, 10.0 + (10.0 * cos(time_passed * 1.5)) * xx);

	set_position(new_position);

  if (time_passed > 10) {
    UtilityFunctions::print("Queue Free");
    queue_free();
    auto e = memnew(GDExample);
    e->set_texture(get_texture());
    e->xx = xx + 1;
    get_parent()->add_child(e);
  }
}

GDREGISTER({
	ClassDB::register_class<GDExample>();
});
