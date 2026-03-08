#pragma once

#include "RenderTypes.hpp"
#include <memory>
#include <string>

struct RenderCommand {
  SpriteId textureId;
  int x, y;
};

class RenderManager {
public:
  virtual ~RenderManager() = default;
  virtual SpriteId RegisterTexture(std::string path) = 0;
  virtual void QueueCommand(RenderCommand command) = 0;
  virtual void RenderQueue() = 0;
};

std::shared_ptr<RenderManager> GetRenderer();
