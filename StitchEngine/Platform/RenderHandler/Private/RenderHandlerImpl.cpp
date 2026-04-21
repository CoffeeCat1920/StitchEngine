#include "RenderHandler.hpp"
#include "TextureHandler.hpp"
#include <raylib.h>
#include <queue>

class RenderHandlerImpl : public RenderHandler {
private:
  TextureHandler& g_textureHandler = GetTextureHandler();

public:
  std::queue<RenderCommand> renderQueue;

  void QueueCommand(RenderCommand command) override {
    renderQueue.push(command);
    return;
  }

  void RenderQueue() override {
    while (!renderQueue.empty()) {
      RenderCommand command = renderQueue.front();
      renderQueue.pop();
      DrawTexture(g_textureHandler.GetTexture(command.textureId), command.x, command.y, WHITE);
    }
  }
};

RenderHandler& GetRenderHandler() {
  static RenderHandlerImpl g_RenderHandler;
  return g_RenderHandler;
};
