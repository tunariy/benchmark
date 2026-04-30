#pragma once

#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <memory>

#define TRACE(...) ::g_Logger.getLogger()->trace(__VA_ARGS__)
#define INFO(...) ::g_Logger.getLogger()->info(__VA_ARGS__)
#define WARN(...) ::g_Logger.getLogger()->warn(__VA_ARGS__)
#define ERR(...) ::g_Logger.getLogger()->error(__VA_ARGS__)
#define CRITICAL(...) ::g_Logger.getLogger()->critical(__VA_ARGS__)

/**
 * @brief spdlogger wrapper
 *
 */
class Logger {
  public:
    Logger() {
        m_Logger = spdlog::stdout_color_mt("GLOBAL");
        m_Logger->set_level(spdlog::level::trace);
    }

    std::shared_ptr<spdlog::logger>& getLogger() { return m_Logger; }

  private:
    std::shared_ptr<spdlog::logger> m_Logger;
};

/**
 * @brief Global logger object
 *
 */
inline Logger g_Logger{};
