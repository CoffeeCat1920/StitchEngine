#pragma once

#include "RenderTypes.hpp"
#include <filesystem>

class ResourceManager {
public:
  virtual SpriteId LoadSprite(std::filesystem::path path) = 0;
  virtual void UnloadSprite(SpriteId spriteId) = 0;
};

ResourceManager &GetResourceManager();
