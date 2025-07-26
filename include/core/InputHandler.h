#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>

namespace MC
{
  // La classe InputHandler gestisce gli eventi di input.
  class InputHandler
  {
  public:
    // Costruttore: inizializza l'input handler.
    InputHandler();
    // Distruttore: non fa nulla.
    ~InputHandler();

    // processEvents gestisce gli eventi di input.
    void processEvents();

    // shouldQuit restituisce true se il gioco deve terminare, altrimenti false.
    bool shouldQuit() const;

  private:
    bool quit;
    const bool *keyboardState; // Stato attuale della tastiera (gestito da SDL)
  };
}
#endif
