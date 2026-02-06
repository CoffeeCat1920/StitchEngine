#include "Window.hpp"
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

  void Run() override {
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(GRAY);
      EndDrawing();
    }
    CloseWindow();
  }
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig) {
  return std::make_unique<RaylibWindow>(windowConfig);
}
