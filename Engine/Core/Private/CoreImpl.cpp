#include "Core.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

#include <memory>

class CoreImpl : public Core {
private:
  std::unique_ptr<Window> window;
  std::shared_ptr<Renderer> renderer;

public:
  CoreImpl(WindowConfig windowCfg) {
    window = GetWindow(windowCfg);
    renderer = GetRenderer();
  }

  void Init() override { window->Init(); }

  void Run() override {
    while (window->IsRunning()) {
      window->Draw(renderer);
    }
    window->Close();
  }
};

std::unique_ptr<Core> GetCore(WindowConfig config) {
  return std::make_unique<CoreImpl>(config);
}
