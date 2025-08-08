#ifndef GAME_H
#define GAME_H

#include "core/Window.h"
#include "core/Renderer.h"
#include "core/InputHandler.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_render.h"

#include "memory"

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

    bool m_IsRunning;
    std::unique_ptr<Window> m_Window;
    std::unique_ptr<InputHandler> m_InputHandler;
    Renderer m_Renderer;
  };
}

#endif // GAME_H