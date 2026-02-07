#include "Renderer.hpp"
#include <memory>
#include <raylib.h>
#include <stack>
#include <unordered_map>

class RendererImpl : public Renderer {
private:
  std::unordered_map<TextureId, Texture2D> textures;
  std::stack<TextureId> availableIds;

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

  void RenderTexture(TextureId textureId, int x = 0, int y = 0) override {
    if (textureId == 0) {
      DrawRectangle(x, y, 64, 64, RED);
      return;
    }
    auto it = textures.find(textureId);
    if (it != textures.end()) {
      DrawTexture(it->second, x, y, WHITE);
    }
  }
};

std::unique_ptr<Renderer> GetRenderer() {
  return std::make_unique<RendererImpl>();
};
