#include <atomic>
#include <chrono>
#include <cstdint>

namespace benchtools {

class Timer;

class ScopedTimer;

class LoggingTimer;

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

static std::chrono::duration<double> gLastDuration{};

std::chrono::duration<double>
durationCast(std::chrono::duration<double> &duration, time_unit durationType);

class Timer {
  using clock = std::chrono::high_resolution_clock;
  using time_point = clock::time_point;

public:
  Timer();

  void start();

  void stop();

  void reset();

  double timeElapsed(time_unit durationType);

  friend ScopedTimer;

private:
  std::chrono::duration<double> currentElapsed();

private:
  time_point mStartPoint;
  std::chrono::duration<double> mElapsedTime{
      std::chrono::duration<double>::zero()};
  std::atomic<bool> mIsRunning{0};
};

class ScopedTimer {
  ScopedTimer() : mTimer(Timer()), mUnit(time_unit::seconds) {};

  ScopedTimer(time_unit unit) : mTimer(Timer()), mUnit(unit) {};

  ~ScopedTimer();

  void setUnit(time_unit unit);

private:
  Timer mTimer;
  time_unit mUnit;
};

class LoggingTimer {}; // TODO

std::string getCurrentTimeDate();
} // namespace benchtools