#include "RenderTypes.hpp"
#include "Renderer.hpp"
#include "TextureManager.hpp"
#include <memory>

class TextureManagerImpl : public TextureManager {
private:
  std::shared_ptr<RenderManager> renderManager;

public:
  TextureManagerImpl(std::shared_ptr<RenderManager> renderManager)
      : renderManager(renderManager) {}

  SpriteId LoadTexture(std::filesystem::path path) override {
    return this->renderManager->RegisterTexture(path);
  }

  void UnloadTexture(SpriteId spriteId) override {
    this->renderManager->FreeTexture(spriteId);
  }
};
