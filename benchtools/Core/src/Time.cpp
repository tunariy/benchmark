#include <benchtools/Core/Time.hpp>
#include <chrono>

namespace benchtools {

std::string getCurrentTimeDate() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  struct tm time_info;
#if defined(__GNUG__)
  localtime_r(&in_time_t, &time_info);
#elif defined(_MSC_VER)
  localtime_s(&time_info, &in_time_t);
#endif
  std::stringstream oss;
  oss << std::put_time(&time_info, "%Y-%m-%d %X");
  return oss.str();
}

Duration durationCast(const std::chrono::duration<double>& duration, time_unit unit) {
  switch (unit) {
  case time_unit::nanoseconds:
    return Duration{std::chrono::duration_cast<std::chrono::nanoseconds>(duration)};
  case time_unit::microseconds:
    return Duration{std::chrono::duration_cast<std::chrono::microseconds>(duration)};
  case time_unit::milliseconds:
    return Duration{std::chrono::duration_cast<std::chrono::milliseconds>(duration)};
  case time_unit::seconds:
    return Duration{std::chrono::duration_cast<std::chrono::seconds>(duration)};
  case time_unit::minutes:
    return Duration{std::chrono::duration_cast<std::chrono::minutes>(duration)};
  case time_unit::hours:
    return Duration{std::chrono::duration_cast<std::chrono::hours>(duration)};
  case time_unit::days:
    return Duration{std::chrono::duration_cast<std::chrono::days>(duration)};
  case time_unit::weeks:
    return Duration{std::chrono::duration_cast<std::chrono::weeks>(duration)};
  case time_unit::months:
    return Duration{std::chrono::duration_cast<std::chrono::months>(duration)};
  case time_unit::years:
    return Duration{std::chrono::duration_cast<std::chrono::years>(duration)};
  default:
    return Duration{std::chrono::duration_cast<std::chrono::seconds>(duration)};
  }
}

std::string format(benchtools::time_unit unit) {
  std::string suffix;
  switch (unit) {
    using enum benchtools::time_unit;
  case nanoseconds:
    suffix = "ns";
    break;
  case microseconds:
    suffix = "us";
    break;
  case milliseconds:
    suffix = "ms";
    break;
  case seconds:
    suffix = "µs";
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
    suffix = "wk";
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

std::string format(duration_t dur) {
  return std::visit(
    [](auto&& arg) -> std::string {
      using T = std::decay_t<decltype(arg)>;
      std::ostringstream oss;
      oss << arg.count();

      if constexpr (std::is_same_v<T, std::chrono::nanoseconds>)
        oss << "ns";
      else if constexpr (std::is_same_v<T, std::chrono::microseconds>)
        oss << "µs";
      else if constexpr (std::is_same_v<T, std::chrono::milliseconds>)
        oss << "ms";
      else if constexpr (std::is_same_v<T, std::chrono::seconds>)
        oss << "s";
      else if constexpr (std::is_same_v<T, std::chrono::minutes>)
        oss << "min";
      else if constexpr (std::is_same_v<T, std::chrono::hours>)
        oss << "h";
      else if constexpr (std::is_same_v<T, std::chrono::days>)
        oss << "d";
      else if constexpr (std::is_same_v<T, std::chrono::weeks>)
        oss << "wk";
      else if constexpr (std::is_same_v<T, std::chrono::months>)
        oss << "mo";
      else if constexpr (std::is_same_v<T, std::chrono::years>)
        oss << "y";
      else
        oss << " [unknown unit]";

      return oss.str();
    },
    dur);
}
}  // namespace benchtools