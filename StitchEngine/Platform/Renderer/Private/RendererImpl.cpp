#include "Renderer.hpp"
#include <memory>
#include <queue>
#include <raylib.h>

class RenderManagerImpl : public RenderManager {
private:
  std::vector<Texture2D> textures;
  std::queue<RenderCommand> renderQueue;

public:
  RenderManagerImpl() {}

  SpriteId RegisterTexture(std::string path) override {
    SpriteId id = textures.size();
    textures.push_back(LoadTexture(path.c_str()));
    return id;
  }

  void QueueCommand(RenderCommand command) override {
    renderQueue.push(command);
    return;
  }

  void RenderQueue() override {
    while (!renderQueue.empty()) {
      RenderCommand command = renderQueue.front();
      renderQueue.pop();
      if (command.textureId < textures.size()) {
        DrawTexture(textures[command.textureId], command.x, command.y, WHITE);
      } else {
        DrawRectangle(command.x, command.y, 64, 64, RED);
      }
    }
  }
};

std::shared_ptr<RenderManager> GetRenderer() {
  return std::make_shared<RenderManagerImpl>();
};
