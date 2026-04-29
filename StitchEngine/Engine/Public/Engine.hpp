#pragma once

#include "Scene.hpp"
#include "WindowTypes.hpp"

#include <memory>

class Engine {
public:
  virtual void LoadScene(Scene scene) = 0;
  virtual void UnloadScene(Scene scene) = 0;
  virtual void Init() = 0;
  virtual void Run() = 0;
};

std::unique_ptr<Engine> GetEngine(WindowConfig config);
