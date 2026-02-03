#include "../Public/Window.hpp"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>

class SDLWindow : public Window {
  void Test() { std::cout << "This is a window"; }
};

std::unique_ptr<Window> GetWindow() { return std::make_unique<SDLWindow>(); }
