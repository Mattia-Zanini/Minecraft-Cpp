#include "core/Window.h"
#include "logmanager/logger.h"

#include "glad/glad.h"

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_opengl.h"

// #include "OpenGL/gl3.h"

#include "string"

namespace MC
{
  Window::Window()
  {
    initVars();
  }

  Window::~Window()
  {
    if (m_Window)
    {
      SDL_DestroyRenderer(m_Renderer);
      LOGGER_INFO("Destroyed the renderer");

      SDL_DestroyWindow(m_Window);
      LOGGER_INFO("Destroyed the window");

      SDL_Quit();
      LOGGER_INFO("Clean up all initialized SDL subsystems");
    }

    initVars();
  }

  bool Window::createWindow(const char *title, int width, int height, int minWidth, int minHeight, SDL_WindowFlags flags)
  {
    LOGGER_INFO("Beginning the operations to create the window");

    // Inizializzo la libreria SDL
    if (SDL_Init(SDL_INIT_VIDEO) == false)
    {
      LOGGER_ERROR("Couldn't initialize SDL: {}", SDL_GetError());
      return m_Created;
    }

    // Imposto gli attributi di OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

#ifndef OS_APPLE
    // imposto questo attributo perchè apple ha interrotto il supporto per OpenGL,
    // dunque l'ultima versione supportata da macosx è OpenGL 4.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
#endif // !OS_APPLE

    // Creo la finestra
    m_Window = SDL_CreateWindow(title, width, height, flags);
    if (m_Window == nullptr)
    {
      LOGGER_ERROR("Couldn't create window: {}", SDL_GetError());
      return m_Created;
    }

    // Acquisizione del contesto OpenGL
    m_GlContext = SDL_GL_CreateContext(m_Window);
    if (m_GlContext == nullptr)
    {
      LOGGER_ERROR("Failed to create OpenGL context: {}", SDL_GetError());
      return m_Created;
    }

    // Inizializza GLAD per caricare i puntatori alle funzioni di OpenGL
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
      LOGGER_ERROR("Failed to initialize GLAD: {}", glad_glGetError());
      return m_Created;
    }

    // Ottengo la versione presente nel sistema di OpenGL
    const GLubyte *version = glGetString(GL_VERSION);
    if (version)
    {
      LOGGER_INFO("OpenGL Version: {}", (const char *)version);
    }
    else
    {
      LOGGER_ERROR("Failed to get OpenGL version");
    }

    // Imposto la dimensione minima della finestra
    if (SDL_SetWindowMinimumSize(m_Window, minWidth, minHeight) == false)
    {
      LOGGER_ERROR("Couldn't set minimum window size: {}", SDL_GetError());
    }

    m_Renderer = SDL_CreateRenderer(m_Window, nullptr);
    if (m_Renderer == nullptr)
    {
      LOGGER_ERROR("Couldn't create renderer: {}", SDL_GetError());
      return m_Created;
    }

    m_Created = true;
    LOGGER_INFO("Window and Renderer created");
    return m_Created;
  }

  void Window::initVars()
  {
    m_Created = false;

    m_Window = nullptr;
    m_Renderer = nullptr;
    m_Surface = nullptr;
    m_Texture = nullptr;
    m_Event = nullptr;
  }

  SDL_Renderer *Window::getRenderer() const { return m_Renderer; }
}