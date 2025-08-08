#ifndef RENDERER_H
#define RENDERER_H

// Dichiarazione anticipata di SDL_Renderer per evitare di includere l'header SDL completo qui.
// Questa è una buona pratica per ridurre i tempi di compilazione.
struct SDL_Renderer;

namespace MC
{
  class Renderer
  {
  public:
    Renderer();
    void setRenderer(SDL_Renderer *sdlRenderer);
    ~Renderer();

    // Disabilita la copia e l'assegnazione, poiché questa classe gestisce un puntatore raw.
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;

  private:
    // Un puntatore non proprietario al renderer SDL principale gestito dalla classe Window.
    // Non serve gestire il ciclo di vita del renderer, perchè ci pensa SDL (nella classe Window)
    SDL_Renderer *m_SdlRenderer;
  };
}

#endif // RENDERER_H
