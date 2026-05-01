#pragma once

#include <cstdint>
#include <string>

namespace benchtools {

enum class LogType : uint8_t {
    TIMER,
    INFO,
    TRACE,
    WARNING,
    ERROR,
};

[[nodiscard]] inline std::string format(LogType type) {
    switch (type) {
        using enum benchtools::LogType;
    case TIMER:
        return " [TIMER] ";
    case INFO:
        return " [INFO] ";
    case TRACE:
        return " [TRACE] ";
    case WARNING:
        return " [WARNING] ";
    case ERROR:
        return " [ERROR] ";
    default:
        return " [UNKNOWN ENUM] ";
    }
}
};  // namespace benchtools