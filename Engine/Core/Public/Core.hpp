#pragma once

#include "WindowTypes.hpp"

#include <memory>

class Core {
public:
  virtual void Init() = 0;
  virtual void Run() = 0;
};

std::unique_ptr<Core> GetCore(WindowConfig config);
