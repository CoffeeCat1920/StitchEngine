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

  void BeginFrame() override {
    BeginDrawing();
    ClearBackground(GRAY);
  }

  void EndFrame() override { EndDrawing(); }

  void Close() override { CloseWindow(); }

  bool IsRunning() override { return !WindowShouldClose(); }
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig) {
  return std::make_unique<RaylibWindow>(windowConfig);
}
