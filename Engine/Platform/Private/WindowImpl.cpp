#include "Renderer.hpp"
#include "Window.hpp"
#include <memory>
#include <raylib.h>
#include <utility>

class RaylibWindow : public Window {
private:
  std::unique_ptr<Renderer> renderer;

public:
  RaylibWindow(WindowConfig cfg, std::unique_ptr<Renderer> &&renderer)
      : Window(cfg), renderer(std::move(renderer)) {}

  ~RaylibWindow() {}

  void Init() override {
    WindowConfig cfg = Window::GetConfig();
    InitWindow(cfg.w, cfg.h, cfg.title.c_str());
    SetTargetFPS(60);
  }

  void Run() override {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(GRAY);
      renderer->RenderQueue();
      EndDrawing();
    }
    CloseWindow();
  }

  bool IsRunning() override { return !WindowShouldClose(); }
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig,
                                  std::unique_ptr<Renderer> &&renderer) {
  return std::make_unique<RaylibWindow>(windowConfig, std::move(renderer));
}
