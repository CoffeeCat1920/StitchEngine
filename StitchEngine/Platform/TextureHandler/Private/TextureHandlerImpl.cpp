#include "FreeList.hpp"
#include "TextureHandler.hpp"
#include <cstdint>
#include <raylib.h>

inline const uint16_t MAX_SPRITE_ID = UINT16_MAX;
  

class TextureHanderImpl : public TextureHandler {
private:
  FreeList<Texture2D> textures;
public:
  SpriteId LoadTexture(std::filesystem::path path) override {}
  void UnloadTexture(SpriteId id) override {}
};
