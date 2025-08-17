#include "logmanager/logger.h"
#include <memory>

namespace MC
{
  // init inizializza e configura il logger di spdlog.
  void Logger::init()
  {
    // Crea un "sink" per la console che supporta i colori per i diversi livelli di log.
    auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    // Imposta il formato dei messaggi di log.
    // Esempio: [17-08-2025 10:30:05.123] [info] [MCLogger]: Messaggio di log
    consoleSink->set_pattern("[%d-%m-%Y %H:%M:%S.%e] [%l] [%n]: %v%$");

    // Un logger può avere più sink (es. console e file). Qui usiamo solo la console.
    std::vector<spdlog::sink_ptr> sinks{consoleSink};

    // Crea il logger vero e proprio con un nome e i sink configurati.
    auto logger = std::make_shared<spdlog::logger>(LOGGER_DEFAULT_NAME, sinks.begin(), sinks.end());

    // Imposta il livello minimo di log da registrare (trace è il più basso, quindi registra tutto).
    logger->set_level(spdlog::level::trace);
    // Fa in modo che i messaggi vengano scritti immediatamente (utile per il debug in caso di crash).
    logger->flush_on(spdlog::level::trace);

    // Registra il logger appena creato per renderlo accessibile globalmente tramite spdlog::get().
    spdlog::register_logger(logger);
  }

  // shutdown rilascia le risorse utilizzate da spdlog.
  void Logger::shutdown()
  {
    spdlog::shutdown();
  }

  // Il costruttore chiama init() per configurare il logger all'avvio.
  Logger::Logger()
  {
    init();
    LOGGER_INFO("Logger initialized");
  }

  // Il distruttore chiama shutdown() per una pulizia ordinata.
  Logger::~Logger()
  {
    LOGGER_INFO("Logger is shutting down");
    shutdown();
  }
}