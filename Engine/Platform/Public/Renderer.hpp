#pragma once

#include <cstdint>
#include <raylib.h>
#include <string>

using TextureId = uint8_t;

class Renderer {
public:
  virtual ~Renderer() = default;
  virtual TextureId RegisterTexture(std::string path) = 0;
  virtual void RenderTexture(TextureId id, int x = 0, int y = 0) = 0;
};
