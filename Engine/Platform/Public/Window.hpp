#pragma once

#include <cstdint>
#include <memory>
#include <string>

struct WindowConfig {
  uint16_t w, h;
  std::string title;
  WindowConfig() : w(640), h(480), title("") {}
  WindowConfig(uint16_t w, uint16_t h, std::string title)
      : w(w), h(h), title(title) {}
  WindowConfig(std::string title) : w(640), h(480), title(title) {}
};

class Window {
private:
  WindowConfig cfg;

protected:
  WindowConfig &GetConfig() { return cfg; }

public:
  virtual ~Window() = default;
  Window(WindowConfig cfg) : cfg(cfg) {}
  virtual void Init() = 0;
  virtual void Run() = 0;
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig);
