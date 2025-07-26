#include "../include/core/InputHandler.h"
#include <SDL3/SDL_keyboard.h>
#include <cstring> // Per memcpy

namespace MC
{
  // Costruttore: inizializza lo stato di quit a false e ottiene lo stato della tastiera.
  InputHandler::InputHandler() : quit(false)
  {
    keyboardState = SDL_GetKeyboardState(NULL);
  }

  // Distruttore: non fa nulla.
  InputHandler::~InputHandler() {}

  // processEvents gestisce gli eventi SDL, impostando quit a true se viene rilevato l'evento di chiusura.
  void InputHandler::processEvents()
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
        quit = true;
    }
  }

  // shouldQuit restituisce true se il gioco deve terminare, altrimenti false.
  bool InputHandler::shouldQuit() const { return quit; }
}
