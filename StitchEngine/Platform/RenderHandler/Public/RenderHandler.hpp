#pragma once

#include "RenderTypes.hpp"

struct RenderCommand {
  SpriteId textureId;
  int x, y;
};

class RenderHandler {
public:
  virtual ~RenderHandler() = default;
  virtual void QueueCommand(RenderCommand command) = 0;
  virtual void RenderQueue() = 0;
};

RenderHandler &GetRenderHandler();
