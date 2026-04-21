#include "RenderHandler.hpp"
#include "TextureHandler.hpp"
#include <queue>
#include <raylib.h>

class RenderHandlerImpl : public RenderHandler {
private:
  TextureHandler &g_textureHandler = GetTextureHandler();
  std::queue<RenderCommand> renderQueue;

public:
  void QueueCommand(RenderCommand command) override {
    renderQueue.push(command);
  }

  void RenderQueue() override {
    while (!renderQueue.empty()) {
      RenderCommand command = renderQueue.front();
      renderQueue.pop();
      DrawTexture(g_textureHandler.GetTexture(command.textureId), command.x,
                  command.y, WHITE);
    }
  }
};

RenderHandler &GetRenderHandler() {
  static RenderHandlerImpl g_RenderHandler;
  return g_RenderHandler;
};
