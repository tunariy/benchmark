#pragma once

#include <concepts>
#include <string>
#include <type_traits>

namespace benchtools {

class ClockTimer;
class WallTimer;

template <typename T>
concept ToStringConv =
    std::convertible_to<T, std::string> || std::convertible_to<T, std::string_view>;

template <typename T>
concept IsTimer = std::is_same_v<T, ClockTimer> || std::is_same_v<T, WallTimer>;
};  // namespace benchtools