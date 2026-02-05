#include <SDL3/SDL.h>
#include <iostream>
#include <memory>

#include "Window.hpp"

class SDLWindow : public Window {
private:
public:
  SDLWindow(WindowConfig windowConfig) : Window(windowConfig) {}
  void Init() { std::cout << "Initiating\n"; }
  void Run() { std::cout << "Run\n"; }
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig) {
  return std::make_unique<SDLWindow>(windowConfig);
}
