#include "Renderer.hpp"
#include "Window.hpp"
#include <memory>
#include <raylib.h>

class RaylibWindow : public Window {
private:
public:
  RaylibWindow(WindowConfig cfg) : Window(cfg) {}

  ~RaylibWindow() {}

  void Init() override {
    WindowConfig cfg = Window::GetConfig();
    InitWindow(cfg.w, cfg.h, cfg.title.c_str());
    SetTargetFPS(60);
  }

  void Draw(Renderer *renderer) override {
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

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig) {
  return std::make_unique<RaylibWindow>(windowConfig);
}
