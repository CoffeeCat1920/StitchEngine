#pragma once

#include "RenderTypes.hpp"
#include <filesystem>

class ResourceManager {
public:
  ResourceManager();
  virtual void LoadTexture(std::filesystem::path path) = 0;
  virtual void UnloadTexture(SpriteId spriteId) = 0;
};
