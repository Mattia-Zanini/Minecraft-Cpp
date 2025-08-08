#include "core/Renderer.h"

#include "logmanager/logger.h"

namespace MC
{
  Renderer::Renderer()
  {
    m_SdlRenderer = nullptr;
  }

  void Renderer::setRenderer(SDL_Renderer *sdlRenderer)
  {
    LOGGER_ASSERT(sdlRenderer != nullptr, "You are trying to set the renderer pointer as nullptr");
    m_SdlRenderer = sdlRenderer;
  }

  Renderer::~Renderer()
  {
    // Il distruttore è vuoto perché questa classe non possiede m_SdlRenderer.
    // La classe Window è responsabile della sua distruzione.
  }
}
