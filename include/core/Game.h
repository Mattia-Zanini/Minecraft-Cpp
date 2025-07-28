#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "InputHandler.h"
#include "logmanager/logger.h"
#include <SDL3/SDL_render.h>
#include <memory>

namespace MC
{
  class Game
  {
  public:
    Game();
    ~Game();

    void run();

  private:
    void initVars();
    void processEvents();
    void update();
    void render();

    bool isRunning;
    std::unique_ptr<Window> window;
    std::unique_ptr<InputHandler> inputHandler;
    SDL_Renderer *renderer;
  };
}

#endif // GAME_H