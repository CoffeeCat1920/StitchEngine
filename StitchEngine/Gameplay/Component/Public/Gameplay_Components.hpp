#pragma once

#include "ComponentRegistry.hpp"
#include "MathsTypes.hpp"

struct CTransform {
  Vec2 position{0, 0};
  Vec2 scale{1, 1};
  float rotation = 0.0f;
  COMPONENT(CTransform, position, scale)
};
REFLECTION(CTransform);
