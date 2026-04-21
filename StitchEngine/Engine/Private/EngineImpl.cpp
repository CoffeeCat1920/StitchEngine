#include "Engine.hpp"
#include "RenderHandler.hpp"
#include "TextureHandler.hpp"
#include "WindowHandler.hpp"

#include <memory>

class EnineImpl : public Engine {
private:
  WindowHandler &g_windowHandler;
  RenderHandler &g_renderHandler;
  TextureHandler &g_textureHandler;

public:
  EnineImpl(WindowConfig windowCfg)
      : g_windowHandler(GetWindowHandler(windowCfg)),
        g_renderHandler(GetRenderHandler()),
        g_textureHandler(GetTextureHandler()) {}

  void Init() override { g_windowHandler.Init(); }

  void Run() override {
    while (g_windowHandler.IsRunning()) {
      g_windowHandler.BeginFrame();
      g_renderHandler.RenderQueue();

      g_windowHandler.EndFrame();
    }
    g_windowHandler.Close();
  }
};

std::unique_ptr<Engine> GetEngine(WindowConfig config) {
  return std::make_unique<EnineImpl>(config);
}
