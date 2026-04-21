#include "Engine.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

#include <memory>

class EnineImpl : public Engine {
private:
  std::unique_ptr<Window> window;
  std::shared_ptr<RenderManager> renderer;
  SpriteId sprite;

public:
  EnineImpl(WindowConfig windowCfg) {
    window = GetWindow(windowCfg);
    renderer = GetRenderer();
  }

  void Init() override {
    window->Init();

    sprite = renderer->RegisterTexture(
        "lamar.png");
  }

  void Run() override {
    while (window->IsRunning()) {
      renderer->QueueCommand(
          RenderCommand{.textureId = sprite, .x = 0, .y = 0});
      window->BeginFrame();
      renderer->RenderQueue();
      window->EndFrame();
    }
    window->Close();
  }
};

std::unique_ptr<Engine> GetEngine(WindowConfig config) {
  return std::make_unique<EnineImpl>(config);
}
