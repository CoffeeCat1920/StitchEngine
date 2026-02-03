#pragma once

#include <memory>

class Window {
public:
  Window() {}
  virtual void Test() = 0;
};

std::unique_ptr<Window> GetWindow();
