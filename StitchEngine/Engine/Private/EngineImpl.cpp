#include "Engine.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

#include <iostream>
#include <memory>

class EnineImpl : public Engine {
private:
  std::unique_ptr<Window> window;
  std::shared_ptr<Renderer> renderer;
  SpriteId sprite;

public:
  EnineImpl(WindowConfig windowCfg) {
    window = GetWindow(windowCfg);
    renderer = GetRenderer();
  }

  void Init() override {
    window->Init();

    sprite = renderer->RegisterTexture(
        "/home/ok/Code/stitchEngine/Game/src/cat.jpg");
    std::cout << sprite << "\n";
  }

  void Run() override {
    while (window->IsRunning()) {
      window->BeginFrame();
      renderer->QueueCommand(
          RenderCommand{.textureId = sprite, .x = 0, .y = 0});
      renderer->RenderQueue();
      window->EndFrame();
    }
    window->Close();
  }
};

std::unique_ptr<Engine> GetEngine(WindowConfig config) {
  return std::make_unique<EnineImpl>(config);
}
