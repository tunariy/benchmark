#pragma once

#include <benchtools/Core/FileStream.hpp>

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

namespace benchtools {

/**
 * @brief TODO: DO SHIT
 *
 * @tparam T
 */
template <typename T>
concept ToStringConv =
    std::convertible_to<T, std::string> || std::convertible_to<T, std::string_view>;

template <size_t N> class CSVStream {

  public:
    CSVStream() = delete;

    template <typename... Args>
        requires(sizeof...(Args) == N) && (ToStringConv<Args> && ...)
    CSVStream(std::string_view path, Args&&... args)
        : m_Stream(path), m_Headers{std::forward<Args>(args)...} {
        uint8_t l_counter{1};
        for (const auto& header : m_Headers) {
            m_Stream.append(std::string(header));
            if (l_counter++ < N) {
                m_Stream.append(",");
            }
        }
        m_Stream.append("\n");
    }

    template <size_t S> CSVStream() {}

    template <typename... Args>
        requires(sizeof...(Args) == N) && (ToStringConv<Args> && ...)
    void write(Args&&... args) {
        std::array<std::string, N> temp = {(args)...};
        uint8_t l_counter{1};
        for (const auto& content : temp) {
            m_Stream.append(std::string(content));
            if (l_counter++ < N) {
                m_Stream.append(",");
            }
        }
        m_Stream.append("\n");
    };

  private:
    FileStream m_Stream{};
    std::array<std::string, N> m_Headers;
};
};  // namespace benchtools