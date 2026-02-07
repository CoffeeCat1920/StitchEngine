#include "Renderer.hpp"
#include <memory>
#include <raylib.h>
#include <stack>
#include <unordered_map>

class RendererImpl : public Renderer {
private:
  std::unordered_map<TextureId, Texture2D> textures;
  std::stack<TextureId> availableIds;
  std::stack<RenderCommand> renderStack;

public:
  RendererImpl() {
    for (int i = 1; i <= 255; i++) {
      availableIds.push(i);
    }
  }

  TextureId RegisterTexture(std::string path) override {
    if (availableIds.empty()) {
      return 0;
    }
    TextureId id = availableIds.top();
    availableIds.pop();
    textures[id] = LoadTexture(path.c_str());
    return id;
  }

  void RenderTexture(RenderCommand command) override {
    if (command.textureId == 0) {
      DrawRectangle(command.x, command.y, 64, 64, RED);
      return;
    }
    renderStack.push(command);
    return;
  }

  void Update() override {
    while (!renderStack.empty()) {
      RenderCommand command = renderStack.top();
      renderStack.pop();
      auto it = textures.find(command.textureId);
      if (it != textures.end()) {
        DrawTexture(it->second, command.x, command.y, WHITE);
      }
    }
  }
};

std::unique_ptr<Renderer> GetRenderer() {
  return std::make_unique<RendererImpl>();
};
