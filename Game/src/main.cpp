#include "Renderer.hpp"
#include "Window.hpp"
#include <memory>

int main() {
  WindowConfig windowConfig("Test");
  auto renderer = GetRenderer();
  auto window = GetWindow(windowConfig);
  window->Init();
  auto sprite =
      renderer->RegisterTexture("/home/ok/Code/stitchEngine/Game/src/cat.jpg");
  renderer->QueueCommand(
      RenderCommand{.textureId = sprite, .x = 100, .y = 100});

  window->Draw(renderer.get());
}
