#include "core/Game.h"
#include "logmanager/logger.h"

#include <cstdlib>
#include <exception>

int main(int argc, char* argv[]) {
  // Inizializza il logger
  MC::Logger loggerManager;
  LOGGER_INFO("SDL version: {}.{}.{}", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_MICRO_VERSION);
  LOGGER_INFO("Platform: {}", OS);

  try {
    MC::Game app{};
    app.run();
  } catch (const std::exception& e) {
    LOGGER_FATAL("Fatal error: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
