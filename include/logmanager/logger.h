#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace MC
{
  // La classe Logger gestisce la registrazione dei messaggis
  class Logger
  {
  public:
    // Inizializza il logger
    void init();
    // Arresta il logger
    void shutdown();
  };
}
#endif

#define LOGGER_DEFAULT_NAME "MCLogger"

// Macro di logging che il resto dell'app userà
#ifndef LOGGER_ENABLED
#define LOGGER_TRACE(...)                                 \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)        \
  {                                                       \
    spdlog::get(LOGGER_DEFAULT_NAME)->trace(__VA_ARGS__); \
  }

#define LOGGER_DEBUG(...)                                 \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)        \
  {                                                       \
    spdlog::get(LOGGER_DEFAULT_NAME)->debug(__VA_ARGS__); \
  }

#define LOGGER_INFO(...)                                 \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)       \
  {                                                      \
    spdlog::get(LOGGER_DEFAULT_NAME)->info(__VA_ARGS__); \
  }

#define LOGGER_WARN(...)                                 \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)       \
  {                                                      \
    spdlog::get(LOGGER_DEFAULT_NAME)->warn(__VA_ARGS__); \
  }

#define LOGGER_ERROR(...)                                 \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)        \
  {                                                       \
    spdlog::get(LOGGER_DEFAULT_NAME)->error(__VA_ARGS__); \
  }

#define LOGGER_FATAL(...)                                    \
  if (spdlog::get(LOGGER_DEFAULT_NAME) != nullptr)           \
  {                                                          \
    spdlog::get(LOGGER_DEFAULT_NAME)->critical(__VA_ARGS__); \
  }

#define LOGGER_ASSERT(x, msg)                                                                     \
  if ((x))                                                                                        \
  {                                                                                               \
  }                                                                                               \
  else                                                                                            \
  {                                                                                               \
    LOGGER_FATAL("ASSERT - {}\n\t{}\n\tin file: {}\n\tin line: {}", #x, msg, __FILE__, __LINE__); \
  }

#else
#define LOGGER_TRACE(...) void(0)
#define LOGGER_DEBUG(...) void(0)
#define LOGGER_INFO(...) void(0)
#define LOGGER_WARN(...) void(0)
#define LOGGER_ERROR(...) void(0)
#define LOGGER_FATAL(...) void(0)

#endif