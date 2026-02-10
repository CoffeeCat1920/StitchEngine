#pragma once

#include "RenderTypes.hpp"
#include <memory>
#include <string>

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
