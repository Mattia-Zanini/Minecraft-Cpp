#include "core/Renderer.h"

#include "logmanager/logger.h"

#include "glad/glad.h"
#include "SDL3/SDL_video.h"

namespace MC
{
  Renderer::Renderer(SDL_Window* window)
  {
    m_SdlWindow = window;
  }

  Renderer::~Renderer()
  {
  }

  void Renderer::clear() const
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Renderer::swapBuffers() const
  {
    SDL_GL_SwapWindow(m_SdlWindow);
  }
}
