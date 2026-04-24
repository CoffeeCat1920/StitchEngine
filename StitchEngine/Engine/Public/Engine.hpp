#pragma once

#include "ECS.hpp"
#include "WindowTypes.hpp"

#include <memory>

class Engine {
public:
  virtual void Init() = 0;
  virtual void Run() = 0;
};

std::unique_ptr<Engine> GetEngine(WindowConfig config);
