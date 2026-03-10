#pragma once

#include "RenderTypes.hpp"
#include <filesystem>
#include <memory>

class TextureManager {
public:
  TextureManager();
  virtual SpriteId LoadTexture(std::filesystem::path path) = 0;
  virtual void UnloadTexture(SpriteId spriteId) = 0;
};

std::unique_ptr<TextureManager> GetTextureManager();
