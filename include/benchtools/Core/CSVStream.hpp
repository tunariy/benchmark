#pragma once

#include <benchtools/Core/FileStream.hpp>

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>

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

    /**
     * @brief
     *
     * @tparam Args the headers of the CSV file
     */
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

    /**
     * @brief
     *
     * @tparam L
     */
    template <size_t L>
        requires(L == N)
    CSVStream(std::string_view path, std::array<std::string_view, L> headers)
        : m_Stream(path), m_Headers(headers) {
        uint8_t l_counter{1};
        for (const auto& header : m_Headers) {
            m_Stream.append(std::string(header));
            if (l_counter++ < N) {
                m_Stream.append(",");
            }
        }
        m_Stream.append("\n");
    }

    /**
     * @brief
     *
     * @tparam Args
     */
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

    /**
     * @brief
     *
     * @tparam L must be equal to header size of CSV Handler
     */
    template <size_t L>
        requires(N == L)
    void write(std::array<std::string_view, L> contents) {
        uint8_t l_counter{1};
        for (const auto& content : contents) {
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