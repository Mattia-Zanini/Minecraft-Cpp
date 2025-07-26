#include "core/Window.h"
#include "logmanager/logger.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdexcept>
#include <string>

namespace MC
{
  Window::Window()
  {
    initVars();
  }

  Window::~Window()
  {
    if (created)
    {
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
    }

    initVars();
  }

  bool Window::createWindow(const char *title, int width, int height, int minWidth, int minHeight, SDL_WindowFlags flags)
  {

    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
      LOGGER_ERROR("Couldn't initialize SDL: {}", SDL_GetError());
      return created;
    }

    window = SDL_CreateWindow(title, width, height, flags);
    if (window == nullptr)
    {
      LOGGER_ERROR("Couldn't create window: {}", SDL_GetError());
      return created;
    }

    if (SDL_SetWindowMinimumSize(window, minWidth, minHeight) == false)
    {
      LOGGER_ERROR("Couldn't set minimum window size: {}", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (renderer == nullptr)
    {
      LOGGER_ERROR("Couldn't create renderer: {}", SDL_GetError());
      return created;
    }

    created = true;
    return created;
  }

  void Window::initVars()
  {
    created = false;

    window = nullptr;
    renderer = nullptr;
    surface = nullptr;
    texture = nullptr;
    event = nullptr;
  }

  SDL_Renderer *Window::getRenderer() const { return renderer; }
}