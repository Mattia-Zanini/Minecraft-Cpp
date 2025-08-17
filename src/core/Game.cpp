#include "core/Game.h"
#include "core/InputHandler.h"
#include "core/Window.h"
#include "core/Renderer.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_render.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

namespace MC
{
  // Inizializza le variabili
  void Game::initVars()
  {
    m_IsRunning = true;
  };

  // Costruttore della classe Game
  Game::Game()
  {
    // Inizializza le variabili
    initVars();

    // Crea la finestra
    m_Window = std::make_unique<Window>();
    ASSERT(m_Window, "Window unique pointer is null");
    if (!m_Window->createWindow("Minecraft C++", 1280, 720, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL))
    {
      LOGGER_ERROR("Error during game initialization, couldn't create Window");
      m_IsRunning = false;
      return;
    }

    // Inizializza il gestore di input
    m_InputHandler = std::make_unique<InputHandler>();
    ASSERT(m_InputHandler, "InputHandler unique pointer is null");

    // Ottiene il renderer dalla finestra
    m_Renderer = std::make_unique<Renderer>(m_Window->getSdlWindow());
    ASSERT(m_Renderer, "Renderer unique pointer is null");
  }

  // Distruttore della classe Game
  Game::~Game()
  {
    LOGGER_INFO("Destroying Game object");
  };

  // Avvia il ciclo principale del gioco
  void Game::run()
  {
    if (m_IsRunning == false)
      return;

    while (m_IsRunning)
    {
      processEvents();
      update();
      render();
    }
  }

  // Processa gli eventi di input
  void Game::processEvents()
  {
    m_InputHandler->processEvents();
    if (m_InputHandler->shouldQuit())
      m_IsRunning = false;
  }

  // Aggiorna lo stato del gioco
  void Game::update() {}

  // Renderizza il gioco
  void Game::render()
  {
    m_Renderer->clear();

    // Render game objects here

    m_Renderer->swapBuffers();
  }
}
