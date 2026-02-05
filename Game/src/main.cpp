#include "Window.hpp"
#include <memory>

int main() {
  WindowConfig windowConfig(32, 32);
  std::unique_ptr<Window> window = GetWindow(windowConfig);
  window->Init();
  window->Run();
}
