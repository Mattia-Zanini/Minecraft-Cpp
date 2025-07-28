#include "logmanager/logger.h"

namespace MC
{
  // Inizializza il logger.
  void Logger::init()
  {
    // Crea un sink per la console a colori.
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    // Imposta il pattern del formato di log.
    consoleSink->set_pattern("[%d-%m-%Y %H:%M:%S.%e] [%l] [%n]: %v%$");

    // Crea un vettore di sink e aggiunge il sink della console.
    std::vector<spdlog::sink_ptr> sinks{consoleSink};
    // Crea un logger con il nome predefinito e i sink specificati.
    auto logger = std::make_shared<spdlog::logger>(LOGGER_DEFAULT_NAME, sinks.begin(), sinks.end());
    // Imposta il livello di log a trace.
    logger->set_level(spdlog::level::trace);
    // Imposta il flush automatico per il livello di log trace.
    logger->flush_on(spdlog::level::trace);
    // Registra il logger.
    spdlog::register_logger(logger);
  }

  // Arresta il logger.
  void Logger::shutdown()
  {
    spdlog::shutdown();
  }

  Logger::Logger()
  {
    init();
    LOGGER_INFO("Logger initialized");
  }

  Logger::~Logger()
  {
    LOGGER_INFO("Logger is shutting down");
    shutdown();
  }
}
