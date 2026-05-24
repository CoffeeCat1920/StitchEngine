#include "WindowHandler.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <iostream>

class WindowHandlerImpl : public WindowHandler {
private:
  SDL_Window *gSDL_Window;
  SDL_Renderer *gSDL_Renderer;
  SDL_Event gSDL_Event;

  bool running;

public:
  WindowHandlerImpl(WindowConfig cfg) : WindowHandler(cfg), running(true) {}

  ~WindowHandlerImpl() {
    SDL_DestroyWindow(gSDL_Window);
    SDL_DestroyRenderer(gSDL_Renderer);
  }

  void Init() override {
    WindowConfig cfg = WindowHandler::GetConfig();
    if (!SDL_Init(SDL_INIT_VIDEO)) {
      std::cerr << SDL_GetError() << "\n";
      return;
    }
    gSDL_Window = SDL_CreateWindow(cfg.title.c_str(), cfg.w, cfg.h, 0);
    gSDL_Renderer = SDL_CreateRenderer(gSDL_Window, nullptr);
  }

  void BeginFrame() override {
    while (SDL_PollEvent(&gSDL_Event)) {
      if (gSDL_Event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }
    SDL_SetRenderDrawColor(gSDL_Renderer, 30, 60, 120, 255);
    SDL_RenderClear(gSDL_Renderer);
  }

  void EndFrame() override { SDL_RenderPresent(gSDL_Renderer); }

  void Close() override { running = false; }

  bool IsRunning() override { return running; }
};

WindowHandler &GetWindowHandler(WindowConfig windowConfig) {
  static WindowHandlerImpl g_windowHandler(windowConfig);
  return g_windowHandler;
}
