#include "Engine.hpp"
#include "WindowHandler.hpp"

#include <memory>

class EnineImpl : public Engine {
private:
  std::unique_ptr<WindowHandler> window;

public:
  EnineImpl(WindowConfig windowCfg) {
    window = GetWindow(windowCfg);
  }

  void Init() override {
    window->Init();
  }

  void Run() override {
    while (window->IsRunning()) {
      window->BeginFrame();
      window->EndFrame();
    }
    window->Close();
  }
};

std::unique_ptr<Engine> GetEngine(WindowConfig config) {
  return std::make_unique<EnineImpl>(config);
}
