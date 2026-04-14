#pragma once
#include <chrono>
#include <cstdint>
#include <fmt/format.h>

namespace benchtools {

enum class time_unit : uint8_t {
  months,
  years,
  weeks,
  days,
  hours,
  minutes,
  seconds,
  milliseconds,
  microseconds,
  nanoseconds
};

std::chrono::duration<double> durationCast(std::chrono::duration<double>& duration,
                                           time_unit durationType);
std::string getCurrentTimeDate();

std::string format(benchtools::time_unit unit);
}  // namespace benchtools
