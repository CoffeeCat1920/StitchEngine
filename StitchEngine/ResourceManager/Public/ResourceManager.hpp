#pragma once

#include "Renderer.hpp"
#include <memory>

class ResourceManager {
public:
  ResourceManager(std::shared_ptr<RenderManager>);
  virtual void LoadTexture() = 0;
  virtual void UnloadTexture() = 0;
};
