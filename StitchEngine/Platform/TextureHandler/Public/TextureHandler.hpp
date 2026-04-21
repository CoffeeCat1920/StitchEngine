#pragma once

#include "RenderTypes.hpp"
#include <filesystem>
#include <raylib.h>

class TextureHandler {
public:
  virtual SpriteId RegisterSprite(std::filesystem::path path) = 0; 
  virtual Texture& GetTexture(SpriteId);
  virtual void EraseSprite(SpriteId id) = 0;
  virtual ~TextureHandler() = default;
}; 

TextureHandler& GetTextureHandler();
