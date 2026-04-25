#include "ECS.hpp"
#include "Engine.hpp"
#include "Gameplay_Components.hpp"
#include "Gameplay_Systems.hpp" // Force-links self-registering systems — linker strips them otherwise.
#include "WindowTypes.hpp"

int main() {
  auto engine = GetEngine(WindowConfig{.w = 640, .h = 320, .title = "Candela"});

  auto &g_ECS = ECS::Instance();
  auto entity = g_ECS.AddEntity();
  g_ECS.AddComponent(entity, CTransform{
                                 .position = {.x = 0.0f, .y = 0.0f},
                                 .scale = {.x = 1.0f, .y = 1.0f},
                                 .rotation = 0.0f,
                             });

  engine->Init();
  engine->Run();
}
