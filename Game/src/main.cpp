#include "Core.hpp"
#include "WindowTypes.hpp"

int main() {
  auto core = GetCore(WindowConfig{.w = 640, .h = 320, .title = "Candela"});
  core->Init();
  core->Run();
}
