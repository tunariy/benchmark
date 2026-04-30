#pragma once
#include <filesystem>
#include <fstream>
#include <string_view>

namespace benchtools {

using File = std::filesystem::path;

class FileStream {
  public:
    explicit FileStream(std::string_view path);

    explicit FileStream() = default;

    void append(std::string_view content);

    void clear();

  private:
    std::fstream m_Stream;
    File m_File;
};
}  // namespace benchtools