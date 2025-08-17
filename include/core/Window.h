// Window.h

#ifndef WINDOW_H
#define WINDOW_H

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

#include "memory"

namespace MC
{
  // La classe Window astrae la creazione e la gestione della finestra di gioco tramite SDL.
  class Window
  {
  public:
    // Costruttore: inizializza i valori di default.
    Window();
    // Distruttore: distrugge la finestra e rilascia le risorse SDL.
    ~Window();

    // createWindow crea la finestra di gioco.
    // Restituisce true in caso di successo, false altrimenti.
    bool createWindow(const char *title, int width, int height, int minWidth, int minHeight, SDL_WindowFlags flags);
    
    // getSdlWindow restituisce un puntatore grezzo alla finestra SDL sottostante.
    SDL_Window *getSdlWindow() const;

    // Disabilita la copia e l'assegnazione per garantire che esista una sola istanza della finestra.
    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

  private:
    bool m_Created; // Flag che indica se la finestra è stata creata con successo.
    SDL_Window *m_Window; // Puntatore alla finestra SDL.
    SDL_Surface *m_Surface; // Superficie di disegno associata alla finestra (per rendering software).
    SDL_Texture *m_Texture; // Texture per il rendering hardware.
    SDL_Event *m_Event; // Evento SDL.
    SDL_GLContext m_GlContext; // Contesto OpenGL per il rendering accelerato.

    // initVars inizializza le variabili membro.
    void initVars();
  };
}
#endif // WINDOW_H