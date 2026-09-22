#include "core/Game.h"
#include "core/InputHandler.h"
#include "core/Renderer.h"
#include "core/Window.h"

#include "logmanager/logger.h"

#include "SDL3/SDL_video.h"

#include <algorithm>
#include <chrono>

#define MAX_FRAME_TIME 0.0166666667f

namespace MC {
  // Inizializza le variabili
  void Game::initVars() {
    m_IsRunning = true;
  }

  // Costruttore della classe Game
  Game::Game() {
    initVars();
    LOGGER_INFO("Game initialized successfully");
  }

  // Distruttore della classe Game
  Game::~Game() {
    LOGGER_INFO("Destroying Game object");
  }

  // Avvia il ciclo principale del gioco
  void Game::run() {
    if (!m_IsRunning)
      return;

    // Inizializza il timer usando chrono per avere una precisione elevata (calcolo di dt)
    auto currentTime = std::chrono::high_resolution_clock::now();

    while (m_IsRunning) {
      // Calcola il time step (delta time)
      auto newTime = std::chrono::high_resolution_clock::now();
      float frameTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
      currentTime = newTime;

      // Limita il frame time massimo per evitare scatti eccessivi
      frameTime = std::min(frameTime, MAX_FRAME_TIME);

      processEvents();
      update();
      render();
    }
  }

  // Processa gli eventi di input
  void Game::processEvents() {
    m_InputHandler.processEvents();
    if (m_InputHandler.shouldQuit())
      m_IsRunning = false;
  }

  // Aggiorna lo stato del gioco
  void Game::update() {
    // Aggiornamento dello stato del gioco
  }

  // Renderizza il gioco
  void Game::render() {
    m_Renderer.clear();

    // Render game objects here

    m_Renderer.swapBuffers();
  }
}
