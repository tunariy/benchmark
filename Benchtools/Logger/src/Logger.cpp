#include "Benchtools/Logger/Logger.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

Logger::Logger() {
  Init();
}

void Logger::Init() {
  m_Logger = spdlog::stdout_color_mt("");
  m_Logger->set_level(spdlog::level::trace);
}
