#include "FreeList.hpp"
#include "RenderTypes.hpp"
#include "TextureHandler.hpp"
#include <cstdint>
#include <raylib.h>

inline const uint16_t MAX_SPRITE_ID = UINT16_MAX;
  

class TextureHandlerImpl : public TextureHandler {
private:
  FreeList<Texture2D> textures;

public:

  SpriteId RegisterSprite(std::filesystem::path path) override {
    SpriteId id = textures.Insert(LoadTexture(path.c_str()));
    return id;
  }

  Texture& GetTexture(SpriteId id) override {
    return textures[id]; 
  } 

  void EraseSprite(SpriteId id) override {
    textures.Erase(id);
  }
};

TextureHandler& GetTextureHandler() {
  static TextureHandlerImpl g_textureHandler;
  return g_textureHandler;
}
