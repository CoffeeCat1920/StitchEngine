#pragma once

#include <cstdint>
#include <memory>
#include <string>

using Sprite = uint8_t;

struct RenderCommand {
  Sprite textureId;
  int x, y;
};

class Renderer {
public:
  virtual ~Renderer() = default;
  virtual Sprite RegisterTexture(std::string path) = 0;
  virtual void QueueCommand(RenderCommand command) = 0;
  virtual void RenderQueue() = 0;
};

std::shared_ptr<Renderer> GetRenderer();
