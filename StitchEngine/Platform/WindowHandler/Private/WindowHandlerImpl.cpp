#include "WindowHandler.hpp"
#include <raylib.h>

class WindowHandlerImpl : public WindowHandler {
private:
public:
  WindowHandlerImpl(WindowConfig cfg) : WindowHandler(cfg) {}

  ~WindowHandlerImpl() {}

  void Init() override {
    WindowConfig cfg = WindowHandler::GetConfig();
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNFOCUSED |
                   FLAG_BORDERLESS_WINDOWED_MODE);
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

WindowHandler &GetWindowHandler(WindowConfig windowConfig) {
  static WindowHandlerImpl g_windowHandler(windowConfig);
  return g_windowHandler;
}
