#pragma once

#include "WindowTypes.hpp"

class WindowHandler {
private:
  WindowConfig cfg;

protected:
  WindowConfig &GetConfig() { return cfg; }

public:
  virtual ~WindowHandler() = default;
  WindowHandler(WindowConfig cfg) : cfg(cfg) {}
  virtual bool IsRunning() = 0;
  virtual void Init() = 0;
  virtual void BeginFrame() = 0;
  virtual void EndFrame() = 0;
  virtual void Close() = 0;
};

WindowHandler& GetWindowHandler(WindowConfig windowConfig);
