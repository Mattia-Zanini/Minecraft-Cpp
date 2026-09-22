#include "core/Renderer.h"
#include "core/Window.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_video.h"
#include "glad/glad.h"

namespace MC {
  Renderer::Renderer(Window& window) : Renderer(window.getSdlWindow()) {
  }

  Renderer::Renderer(SDL_Window* window) {
    ASSERT(window, "SDL_Window is null");
    m_SdlWindow = window;
    LOGGER_INFO("Renderer created");
  }

  Renderer::~Renderer() {
    LOGGER_INFO("Destroyed the Renderer");
  }

  void Renderer::clear() const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Renderer::swapBuffers() const {
    SDL_GL_SwapWindow(m_SdlWindow);
  }
}
