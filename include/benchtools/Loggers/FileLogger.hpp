#pragma once

#include <benchtools/Core/FileStream.hpp>
#include <benchtools/Core/LogType.hpp>

#include <string_view>

namespace benchtools {

class FileLogger {
  public:
    explicit FileLogger(std::string_view path) noexcept;

    void Log(std::string_view content, LogType type = LogType::INFO) noexcept;

    ~FileLogger() noexcept;

  private:
    FileStream m_Stream{};
};
};  // namespace benchtools