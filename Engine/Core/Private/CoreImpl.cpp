#include "Core.hpp"
#include "Window.hpp"
#include <memory>
#include <raylib.h>

class CoreImpl : public Core {
private:
  std::unique_ptr<Window> window;

public:
  void Init() override {}
  void BeginFrame() override {}
  void EndFrame() override {}
  bool IsRunning() override { return !WindowShouldClose(); }
};

std::unique_ptr<Core> GetCore() { return std::make_unique<CoreImpl>(); }
