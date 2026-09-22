// Game.h

#ifndef GAME_H
#define GAME_H

#include "core/InputHandler.h"
#include "core/Renderer.h"
#include "core/Window.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_render.h"

#include "memory"

namespace MC {
  // La classe Game è il cuore del gioco.
  // Gestisce il ciclo di gioco principale, l'input, l'aggiornamento dello stato e il rendering.
  class Game {
  public:
    static constexpr int WIDTH = 1280;
    static constexpr int HEIGHT = 720;

    // Costruttore: inizializza il gioco.
    Game();
    // Distruttore: pulisce le risorse del gioco.
    ~Game();

    // Disabilita costruttore di copia e operatore di assegnazione (gestione esplicita delle risorse)
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

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

    // L'ordine di dichiarazione definisce l'ordine di inizializzazione (dall'alto in basso)
    // e di distruzione (in ordine inverso, dal basso in alto). Questo ordine è critico:
    // il renderer e l'input handler dipendono dall'inizializzazione del sottosistema e della finestra.
    Window m_Window{ WIDTH, HEIGHT, "Minecraft C++" };
    InputHandler m_InputHandler{};
    Renderer m_Renderer{ m_Window };
  };
}

#endif // GAME_H
