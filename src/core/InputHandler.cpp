#include "core/InputHandler.h"

#include "SDL3/SDL_keyboard.h"

#include "logmanager/logger.h"

#include <cstring>

namespace MC
{
  // Costruttore: inizializza lo stato di quit a false e ottiene lo stato della tastiera.
  InputHandler::InputHandler() : m_Quit(false)
  {
    m_KeyboardState = SDL_GetKeyboardState(NULL);
    LOGGER_INFO("Input Handler created");
  }

  // Distruttore: non fa nulla.
  InputHandler::~InputHandler()
  {
    LOGGER_INFO("Destroyed the Input Handler");
  }

  // processEvents gestisce gli eventi SDL, impostando quit a true se viene rilevato l'evento di chiusura.
  void InputHandler::processEvents()
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
        m_Quit = true;
    }
  }

  // shouldQuit restituisce true se il gioco deve terminare, altrimenti false.
  bool InputHandler::shouldQuit() const { return m_Quit; }
}
