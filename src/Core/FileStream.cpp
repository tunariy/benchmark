#include <benchtools/Core/FileStream.hpp>
#include <ios>
#include <string_view>

namespace benchtools {

FileStream::FileStream(std::string_view path) : m_Stream(path.data()), m_File(path) {}

void FileStream::append(std::string_view content) {
    if (!m_Stream) {
        return;
    }
    m_Stream.write(content.data(), content.size());
};

}  // namespace benchtools