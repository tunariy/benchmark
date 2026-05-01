#include "benchtools/Core/LogType.hpp"
#include <benchtools/Core/FileStream.hpp>
#include <benchtools/Core/Time.hpp>
#include <benchtools/Loggers/FileLogger.hpp>

#include <sstream>
#include <string_view>

namespace benchtools {

FileLogger::FileLogger(std::string_view path) noexcept {
    static const char* s_start_message = "LOG STARTED";
    m_Stream = FileStream{path};
    std::stringstream oss;
    oss << format(time_date()) << format(LogType::INFO) << s_start_message << "\n";
    m_Stream.append(oss.str());
}

void FileLogger::Log(std::string_view content, LogType type) noexcept {
    std::stringstream oss;
    oss << format(time_date()) << format(type) << content << "\n";
    m_Stream.append(oss.str());
    oss.flush();
}

FileLogger::~FileLogger() noexcept {
    std::stringstream oss;
    oss << format(time_date()) << format(LogType::INFO) << "LOG END" << "\n";
    m_Stream.append(oss.str());
}
};  // namespace benchtools