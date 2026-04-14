#include <Benchtools/Time.hpp>
#include <fmt/format.h>

namespace benchtools {

std::chrono::duration<double> durationCast(std::chrono::duration<double>& duration,
                                           time_unit durationType) {
  switch (durationType) {
  case time_unit::months: {
    return std::chrono::duration_cast<std::chrono::months>(duration);
    break;
  }
  case time_unit::years: {
    return std::chrono::duration_cast<std::chrono::years>(duration);
    break;
  }
  case time_unit::weeks: {
    return std::chrono::duration_cast<std::chrono::weeks>(duration);
    break;
  }
  case time_unit::days: {
    return std::chrono::duration_cast<std::chrono::days>(duration);
    break;
  }
  case time_unit::hours: {
    return std::chrono::duration_cast<std::chrono::hours>(duration);
    break;
  }
  case time_unit::minutes: {
    return std::chrono::duration_cast<std::chrono::minutes>(duration);
    break;
  }
  case time_unit::seconds: {
    return std::chrono::duration_cast<std::chrono::seconds>(duration);
    break;
  }
  case time_unit::milliseconds: {
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    break;
  }
  case time_unit::microseconds: {
    return std::chrono::duration_cast<std::chrono::microseconds>(duration);
    break;
  }
  case time_unit::nanoseconds: {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    break;
  }
  default:
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    break;
  }
}

std::string getCurrentTimeDate() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  struct tm time_info;
#if defined(__GNUG__)
  #define COMPILER_GCC
  localtime_r(&in_time_t, &time_info);
#elif defined(_MSC_VER)
  localtime_s(&time_info, &in_time_t);
#endif
  std::stringstream ss;
  ss << std::put_time(&time_info, "%Y-%m-%d %X");
  return ss.str();
}

std::string format(benchtools::time_unit unit) {
  std::string suffix;
  switch (unit) {
    using enum benchtools::time_unit;
  case seconds:
    suffix = "s";
    break;
  case milliseconds:
    suffix = "ms";
    break;
  case microseconds:
    suffix = "us";
    break;
  case nanoseconds:
    suffix = "ns";
    break;
  case minutes:
    suffix = "min";
    break;
  case hours:
    suffix = "h";
    break;
  case days:
    suffix = "d";
    break;
  case weeks:
    suffix = "w";
    break;
  case months:
    suffix = "mo";
    break;
  case years:
    suffix = "y";
    break;
  }
  return suffix;
}
}  // namespace benchtools