#include "FreeList.hpp"
#include "RenderTypes.hpp"
#include "TextureManager.hpp"
#include <raylib.h>

class TextureManagerImpl : public TextureManager {
private:
  FreeList<Texture2D> textures; 

public:
  TextureManagerImpl(){}

  SpriteId LoadTexture(std::filesystem::path path) override {}

  void UnloadTexture(SpriteId spriteId) override {}
};
