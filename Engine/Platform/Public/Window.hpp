#pragma once

#include <cstdint>
#include <memory>

struct WindowConfig {
  uint16_t w, h;
  WindowConfig() : w(32), h(32) {}
  WindowConfig(uint16_t w, uint16_t h) : w(w), h(h) {}
};

class Window {
private:
  WindowConfig windowConfig;

public:
  Window(WindowConfig windowConfig) : windowConfig(windowConfig) {}
  virtual void Init() = 0;
  virtual void Run() = 0;
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig);
