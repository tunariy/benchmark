#pragma once
#include <chrono>
#include <cstdint>

namespace benchtools {

enum class time_unit : uint8_t {
  months,
  years,
  weeks,
  days,
  hours,
  minutes,
  seconds,
  miliseconds,
  microseconds,
  nanoseconds
};

std::chrono::duration<double> durationCast(std::chrono::duration<double>& duration,
                                           time_unit durationType);
std::string getCurrentTimeDate();
}  // namespace benchtools