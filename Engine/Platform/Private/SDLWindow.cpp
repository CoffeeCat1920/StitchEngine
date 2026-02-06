#include "Window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <iostream>
#include <memory>

using SDLWindowPtr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using SDLRendererPtr =
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

class SDLWindow : public Window {
private:
  SDLWindowPtr sdlWindow{nullptr, SDL_DestroyWindow};
  SDLRendererPtr sdlRenderer{nullptr, SDL_DestroyRenderer};

public:
  SDLWindow(WindowConfig windowConfig) : Window(windowConfig) {}

  ~SDLWindow() {
    sdlRenderer.reset();
    sdlWindow.reset();
    SDL_Quit();
  }

  void Init() override {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      std::cout << SDL_GetError() << "\n";
      return;
    }

    sdlWindow.reset(SDL_CreateWindow("SDL Tutorial", Window::GetConfig().w,
                                     Window::GetConfig().h, 0));
    if (!sdlWindow) {
      std::cout << SDL_GetError() << "\n";
      return;
    }

    // Keep renderer alive as member variable
    sdlRenderer.reset(SDL_CreateRenderer(sdlWindow.get(), NULL));
    if (!sdlRenderer) {
      std::cout << SDL_GetError() << "\n";
      return;
    }

    SDL_SetRenderDrawColor(sdlRenderer.get(), 255, 0, 0, 255);
    SDL_RenderClear(sdlRenderer.get());
    SDL_RenderPresent(sdlRenderer.get());
  }

  void Run() override {
    bool running = true;
    while (running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
          running = false;
        }
      }
      SDL_RenderPresent(sdlRenderer.get());
    }
  }
};

std::unique_ptr<Window> GetWindow(WindowConfig windowConfig) {
  return std::make_unique<SDLWindow>(windowConfig);
}
