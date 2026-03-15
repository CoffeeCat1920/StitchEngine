#include "FreeList.hpp"
#include "RenderTypes.hpp"
#include "Renderer.hpp"
#include <memory>
#include <queue>
#include <raylib.h>

class RenderManagerImpl : public RenderManager {
private:
  FreeList<Texture2D> textures;
  std::queue<RenderCommand> renderQueue;

public:
  RenderManagerImpl() {}

  SpriteId RegisterTexture(std::string path) override {
    SpriteId id = textures.Insert(LoadTexture(path.c_str()));
    return id;
  }

  void FreeTexture(SpriteId spriteId) override { textures.Erase(spriteId); }

  void QueueCommand(RenderCommand command) override {
    renderQueue.push(command);
    return;
  }

  void RenderQueue() override {
    while (!renderQueue.empty()) {
      RenderCommand command = renderQueue.front();
      renderQueue.pop();
      DrawTexture(textures[command.textureId], command.x, command.y, WHITE);
    }
  }
};

std::shared_ptr<RenderManager> GetRenderer() {
  return std::make_shared<RenderManagerImpl>();
};
