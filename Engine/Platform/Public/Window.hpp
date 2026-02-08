#pragma once

#include "Types.hpp"
#include <memory>

class Window {
private:
  WindowConfig cfg;

protected:
  WindowConfig &GetConfig() { return cfg; }

public:
  virtual ~Window() = default;
  Window(WindowConfig cfg) : cfg(cfg) {}
  virtual bool IsRunning() = 0;
  virtual void Init() = 0;
  virtual void Draw() = 0;
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig);
