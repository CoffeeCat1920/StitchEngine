#include "Renderer.hpp"
#include <memory>
#include <queue>
#include <raylib.h>
#include <stack>
#include <unordered_map>

class RendererImpl : public Renderer {
private:
  std::unordered_map<SpriteId, Texture2D> textures;
  std::stack<SpriteId> availableIds;
  std::queue<RenderCommand> renderQueue;

public:
  RendererImpl() {
    for (int i = 1; i <= 255; i++) {
      availableIds.push(i);
    }
  }

  SpriteId RegisterTexture(std::string path) override {
    if (availableIds.empty()) {
      return 0;
    }
    SpriteId id = availableIds.top();
    availableIds.pop();
    textures[id] = LoadTexture(path.c_str());
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
      auto it = textures.find(command.textureId);
      if (it != textures.end()) {
        if (command.textureId == 0) {
          DrawRectangle(command.x, command.y, 64, 64, RED);
          return;
        }
        DrawTexture(it->second, command.x, command.y, WHITE);
      }
    }
  }
};

std::shared_ptr<Renderer> GetRenderer() {
  return std::make_shared<RendererImpl>();
};
