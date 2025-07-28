#include "include/core/Game.h"
#include "logmanager/logger.h"

int main(int argc, char *argv[])
{
  // Inizializza il logger
  MC::Logger loggerManager;
  LOGGER_INFO("SLD version: {}.{}.{}", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_MICRO_VERSION);

  // Crea un'istanza del gioco
  MC::Game game;
  // Avvia il ciclo principale del gioco
  game.run();

  return 0;
}
