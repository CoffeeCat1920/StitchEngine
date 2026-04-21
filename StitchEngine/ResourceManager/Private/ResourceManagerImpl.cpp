#include "ResourceManager.hpp"
#include "TextureHandler.hpp"

class ResourceManagerImpl : public ResourceManager {
private:
  TextureHandler &g_textureHandler = GetTextureHandler();

public:
  void LoadSprite(std::filesystem::path path) override {
    g_textureHandler.RegisterSprite(path);
  }

  void UnloadSprite(SpriteId id) override { g_textureHandler.EraseSprite(id); }
};
