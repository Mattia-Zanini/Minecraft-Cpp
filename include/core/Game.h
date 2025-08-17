// Game.h

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
  // La classe Game è il cuore del gioco.
  // Gestisce il ciclo di gioco principale, l'input, l'aggiornamento dello stato e il rendering.
  class Game
  {
  public:
    // Costruttore: inizializza il gioco.
    Game();
    // Distruttore: pulisce le risorse del gioco.
    ~Game();

    // run avvia il ciclo di gioco principale.
    void run();

  private:
    // initVars inizializza le variabili di gioco.
    void initVars();
    // processEvents gestisce gli eventi di input.
    void processEvents();
    // update aggiorna lo stato del gioco.
    void update();
    // render disegna il gioco.
    void render();

    bool m_IsRunning; // Flag che indica se il gioco è in esecuzione.
    std::unique_ptr<Window> m_Window; // La finestra di gioco.
    std::unique_ptr<InputHandler> m_InputHandler; // Il gestore di input.
    std::unique_ptr<Renderer> m_Renderer; // Il renderer.
  };
}

#endif // GAME_H
