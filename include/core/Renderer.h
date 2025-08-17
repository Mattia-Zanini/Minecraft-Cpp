// Renderer.h

#ifndef RENDERER_H
#define RENDERER_H

struct SDL_Window;

namespace MC
{
  // La classe Renderer è responsabile di tutte le operazioni di disegno.
  class Renderer
  {
  public:
    // Costruttore: richiede una finestra SDL per il rendering.
    Renderer(SDL_Window* window);
    // Distruttore.
    ~Renderer();

    // clear pulisce lo schermo con un colore di default.
    void clear() const;
    // swapBuffers scambia i buffer per visualizzare il frame renderizzato.
    void swapBuffers() const;

    // Disabilita la copia e l'assegnazione per prevenire problemi di gestione della memoria.
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

  private:
    SDL_Window *m_SdlWindow; // Puntatore alla finestra SDL (non posseduto da questa classe).
  };
}

#endif // RENDERER_H