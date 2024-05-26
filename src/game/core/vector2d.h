#pragma once

namespace magic_loop {

struct Vector2D {
  float x, y;
};

inline Vector2D operator+(Vector2D lhs, Vector2D rhs) {
  return Vector2D{.x = lhs.x + rhs.x, .y = lhs.x + rhs.y};
}

inline Vector2D operator-(Vector2D lhs, Vector2D rhs) {
  return Vector2D{.x = lhs.x - rhs.x, .y = lhs.x - rhs.y};
}

inline Vector2D operator*(Vector2D lhs, float rhs) {
  return Vector2D{.x = lhs.x * rhs, .y = lhs.x * rhs};
}

inline Vector2D operator/(Vector2D lhs, float rhs) {
  return Vector2D{.x = lhs.x / rhs, .y = lhs.x / rhs};
}

}
