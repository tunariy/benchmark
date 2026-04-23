#include <benchtools/Core/FileStream.hpp>
#include <ios>
#include <string_view>

namespace benchtools {

FileStream::FileStream(std::string_view path)
    : mStream(path.data(), std::ios_base::app), mPath(path) {}

void FileStream::append(const std::string& content) {
  mStream.write(content.c_str(), content.size());
};

void FileStream::clear() {
  // mStream.clear();
}
}  // namespace benchtools