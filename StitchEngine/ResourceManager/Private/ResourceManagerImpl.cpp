#include "ResourceManager.hpp"
#include "TextureManager.hpp"
#include <memory>

class ResourceManagerImpl : public ResourceManager {
private:
  std::unique_ptr<TextureManager> textureManager;
public:
  void LoadTexture(std::filesystem::path path) {
    textureManager->LoadTexture(path);
  } 

  void UnloadTexture(SpriteId spriteId) {
    textureManager->UnloadTexture(spriteId);
  }
};
