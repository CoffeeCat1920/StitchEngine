#include "ECS.hpp"
#include "Engine.hpp"
#include "Gameplay_Components.hpp"
#include "Gameplay_Systems.hpp" // Force-links self-registering systems —
// linker strips them otherwise.
#include "ResourceManager.hpp"
#include "WindowTypes.hpp"

int main() {
  auto engine = GetEngine(WindowConfig{.w = 640, .h = 320, .title = "Candela"});
  engine->Init();

  auto &g_ECS = ECS::Instance();

  auto entity = g_ECS.AddEntity();

  auto &g_resourceManager = GetResourceManager();
  auto test_sprite = g_resourceManager.LoadSprite(
      "/home/ok/Code/StitchEngine/Game/assets/lamar.png");

  g_ECS.AddComponents(entity,
                      CTransform{
                          .position = {.x = 0.0f, .y = 0.0f},
                          .scale = {.x = 1.0f, .y = 1.0f},
                          .rotation = 0.0f,
                      },
                      CSprite{.sprite = test_sprite});

  engine->Run();
}
