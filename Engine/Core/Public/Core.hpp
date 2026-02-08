#pragma once

#include <memory>

class Core {
public:
  virtual void Init() = 0;
  virtual void BeginFrame() = 0;
  virtual void EndFrame() = 0;
  virtual bool IsRunning() = 0;
};

std::unique_ptr<Core> GetCore();
