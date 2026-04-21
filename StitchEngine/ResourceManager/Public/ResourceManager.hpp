#pragma once

#include "RenderTypes.hpp"
#include <filesystem>

class ResourceManager {
public:
  ResourceManager();
  virtual void LoadSprite(std::filesystem::path path) = 0;
  virtual void UnloadSprite(SpriteId spriteId) = 0;
};
