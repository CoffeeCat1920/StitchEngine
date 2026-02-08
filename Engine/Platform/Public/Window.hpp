#pragma once

#include "WindowTypes.hpp"
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
  virtual void BeginFrame() = 0;
  virtual void EndFrame() = 0;
  virtual void Close() = 0;
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig);
