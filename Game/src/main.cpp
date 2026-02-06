#include "Window.hpp"
#include <memory>

int main() {
  WindowConfig windowConfig("Test");
  std::unique_ptr<Window> window = GetWindow(windowConfig);
  window->Init();
  window->Run();
}
