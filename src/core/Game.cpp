#include "core/Game.h"
#include "core/InputHandler.h"
#include "core/Window.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_render.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

namespace MC
{
  // Inizializza le variabili
  void Game::initVars()
  {
    isRunning = true;
    renderer = nullptr;
  };

  // Costruttore della classe Game
  Game::Game()
  {
    // Inizializza le variabili
    initVars();

    // isRunning = false;
    // LOGGER_ASSERT(isRunning == true, "assert test");

    // Crea la finestra
    window = std::make_unique<Window>();
    if (!window->createWindow("Minecraft C++", 1280, 720, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL))
    {
      LOGGER_ERROR("Error during game initialization, couldn't create Window");
      isRunning = false;
      return;
    }

    // Inizializza il gestore di input
    inputHandler = std::make_unique<InputHandler>();

    // Ottiene il renderer dalla finestra
    renderer = window->getRenderer();
  }

  // Distruttore della classe Game
  Game::~Game()
  {
    LOGGER_INFO("Destroying Game object");
    renderer = nullptr;
  };

  // Avvia il ciclo principale del gioco
  void Game::run()
  {
    if (isRunning == false)
      return;

    while (isRunning)
    {
      processEvents();
      update();
      render();
    }
  }

  // Processa gli eventi di input
  void Game::processEvents()
  {
    inputHandler->processEvents();
    if (inputHandler->shouldQuit())
      isRunning = false;
  }

  // Aggiorna lo stato del gioco
  void Game::update() {}

  // Renderizza il gioco
  void Game::render()
  {
    // Imposta il colore di disegno per il renderer
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // Pulisce lo schermo con il colore impostato
    SDL_RenderClear(renderer);

    // Render game objects here

    // Aggiorna lo schermo con il rendering
    SDL_RenderPresent(renderer);
  }
}
