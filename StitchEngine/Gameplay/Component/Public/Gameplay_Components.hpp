#pragma once

#include "ComponentRegistry.hpp"
#include "MathsTypes.hpp"

inline void to_json(nlohmann::json &j, const Vec2 &v) {
  j = {{"x", v.x}, {"y", v.y}};
}

inline void from_json(const nlohmann::json &j, Vec2 &v) {
  j.at("x").get_to(v.x);
  j.at("y").get_to(v.y);
}

struct CTransform {
  Vec2 position{0, 0};
  Vec2 scale{1, 1};
  float rotation = 0.0f;
  COMPONENT(CTransform, position, scale)
};
REFLECTION(CTransform);
