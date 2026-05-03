#pragma once

#include <benchtools/Core/Concepts.hpp>
#include <benchtools/Core/LogType.hpp>
#include <benchtools/Loggers/FileLogger.hpp>

#include <iomanip>
#include <source_location>
#include <string_view>

namespace benchtools {

/**
 * @brief
 *
 * @tparam timer_t
 */
template <typename timer_t>
    requires(IsTimer<timer_t>)
class FileTimer {
  public:
    explicit FileTimer() = delete;

    explicit FileTimer(timer_t& timer, std::string_view path) noexcept
        : m_Timer(&timer), m_Logger(path) {}

    void start(std::source_location loc = std::source_location::current()) noexcept {
        m_Timer->reset();
        m_Timer->start();
        std::stringstream ss;
        ss << loc.file_name() << " " << loc.line() << " " << "Started timer";
        m_Logger.Log(ss.str(), LogType::TIMER);
    }

    void stop(std::source_location loc = std::source_location::current()) noexcept {
        std::stringstream ss;
        m_Timer->stop();
        ss << loc.file_name() << " " << loc.line() << " "
           << "Timer resulted with:" << " " << m_Timer->duration().str();
        m_Logger.Log(ss.str(), LogType::TIMER);
    }

  private:
    timer_t* m_Timer;
    FileLogger m_Logger;
};
};  // namespace benchtools