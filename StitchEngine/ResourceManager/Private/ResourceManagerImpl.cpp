#include "ResourceManager.hpp"
#include "TextureHandler.hpp"

class ResourceManagerImpl : public ResourceManager {
private:
  TextureHandler &g_textureHandler = GetTextureHandler();

public:
  SpriteId LoadSprite(std::filesystem::path path) override {
    return g_textureHandler.RegisterSprite(path);
  }

  void UnloadSprite(SpriteId id) override { g_textureHandler.EraseSprite(id); }
};

ResourceManager &GetResourceManager() {
  static ResourceManagerImpl g_staticResourceManager;
  return g_staticResourceManager;
}
