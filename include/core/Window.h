#ifndef WINDOW_H
#define WINDOW_H

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

#include "memory"

namespace MC
{
  // La classe Window gestisce la finestra di gioco.
  class Window
  {
  public:
    // Costruttore: inizializza la finestra.
    Window();
    // Distruttore: pulisce le risorse della finestra.
    ~Window();

    // createWindow crea una finestra di gioco con le dimensioni e i flag specificati.
    bool createWindow(const char *title, int width, int height, int minWidth, int minHeight, SDL_WindowFlags flags);
    // getRenderer restituisce il renderer della finestra.
    SDL_Renderer *getRenderer() const;

    // Impedisce la copia della finestra.
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

  private:
    bool m_Created;
    SDL_Window *m_Window;
    SDL_Renderer *m_Renderer;
    SDL_Surface *m_Surface;
    SDL_Texture *m_Texture;
    SDL_Event *m_Event;
    SDL_GLContext m_GlContext;

    // Inizializza le variabili della finestra.
    void initVars();
  };
}
#endif // WINDOW_H
