#pragma once

#include <cstdint>
#include <string>

using TextureId = uint8_t;

struct RenderCommand {
  TextureId textureId;
  int x, y;
};

class Renderer {
public:
  virtual ~Renderer() = default;
  virtual TextureId RegisterTexture(std::string path) = 0;
  virtual void RenderTexture(RenderCommand command) = 0;
  virtual void Update();
};
