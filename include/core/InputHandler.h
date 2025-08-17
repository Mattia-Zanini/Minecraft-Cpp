// InputHandler.h

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"

namespace MC
{
  // La classe InputHandler gestisce tutti gli eventi di input dell'utente (tastiera, mouse, etc.).
  class InputHandler
  {
  public:
    // Costruttore: inizializza il gestore di input.
    InputHandler();
    // Distruttore.
    ~InputHandler();

    // processEvents elabora la coda degli eventi di SDL.
    void processEvents();

    // shouldQuit restituisce true se è stato richiesto di chiudere il gioco (es. chiudendo la finestra).
    bool shouldQuit() const;

  private:
    bool m_Quit; // Flag che indica se è stata richiesta la chiusura del gioco.
    const bool *m_KeyboardState; // Puntatore allo stato attuale della tastiera (gestito da SDL).
  };
}
#endif