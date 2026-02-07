#include "Renderer.hpp"
#include "Window.hpp"
#include <memory>
#include <utility>

int main() {
  WindowConfig windowConfig("Test");
  auto renderer = GetRenderer();
  std::unique_ptr<Window> window = GetWindow(windowConfig, std::move(renderer));
  window->Init();
  renderer->RegisterTexture("./Game/src/cat.jpg");
  window->Run();
}
