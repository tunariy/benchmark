#include <ctime>
#include <timer.h>

namespace benchtools {

std::chrono::duration<double>
durationCast(std::chrono::duration<double> &duration, time_unit durationType) {
  switch (durationType) {
  case time_unit::months: {
    return std::chrono::duration_cast<std::chrono::months>(duration);
  } break;
  case time_unit::years: {
    return std::chrono::duration_cast<std::chrono::years>(duration);
  } break;
  case time_unit::weeks: {
    return std::chrono::duration_cast<std::chrono::weeks>(duration);
  } break;
  case time_unit::days: {
    return std::chrono::duration_cast<std::chrono::days>(duration);
  } break;
  case time_unit::hours: {
    return std::chrono::duration_cast<std::chrono::hours>(duration);
  } break;
  case time_unit::minutes: {
    return std::chrono::duration_cast<std::chrono::minutes>(duration);
  } break;
  case time_unit::seconds: {
    return std::chrono::duration_cast<std::chrono::seconds>(duration);
  } break;
  case time_unit::miliseconds: {
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration);
  } break;
  case time_unit::microseconds: {
    return std::chrono::duration_cast<std::chrono::microseconds>(duration);
  } break;
  case time_unit::nanoseconds:
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    break;
  default:
    return std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    break;
  }
}

Timer::Timer() {}

void Timer::start() {
  mStartPoint = std::chrono::high_resolution_clock::now();
  mIsRunning = true;
}

void Timer::stop() {
  if (mIsRunning) {
    mElapsedTime += std::chrono::high_resolution_clock::now() - mStartPoint;
    mIsRunning = false;
  }
}

void Timer::reset() {
  mElapsedTime = std::chrono::duration<double>::zero();
  mIsRunning = false;
}

double Timer::timeElapsed(time_unit durationType) {
  return durationCast(mElapsedTime, durationType).count();
}

std::chrono::duration<double> Timer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mStartPoint;
}

ScopedTimer::~ScopedTimer() {
  mTimer.stop();
  gLastDuration = durationCast(mTimer.mElapsedTime, mUnit);
}

void ScopedTimer::setUnit(time_unit unit) { mUnit = unit; };

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

} // namespace benchtools