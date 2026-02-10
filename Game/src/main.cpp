#include "Engine.hpp"
#include "WindowTypes.hpp"

int main() {
  auto engine = GetEngine(WindowConfig{.w = 640, .h = 320, .title = "Candela"});
  engine->Init();
  engine->Run();
}
