#pragma once

#include "RenderTypes.hpp"
#include <filesystem>

class TextureHandler {
public:
  virtual SpriteId RegisterSprite(std::filesystem::path path) = 0; 
  virtual void EraseSprite(SpriteId id) = 0;
}; 
