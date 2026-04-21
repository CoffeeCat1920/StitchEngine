#pragma once

#include "RenderTypes.hpp"
#include <filesystem>

class TextureHandler {
public:
  virtual SpriteId LoadTexture(std::filesystem::path path) = 0; 
  virtual void UnloadTexture(SpriteId id) = 0;
}; 
