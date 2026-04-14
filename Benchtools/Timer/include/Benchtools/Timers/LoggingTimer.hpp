#pragma once
#include <Benchtools/Timers/Timer.hpp>
#include <chrono>

namespace benchtools {

class LoggingTimer {
public:
  LoggingTimer();

  ~LoggingTimer();

private:
  std::shared_ptr<Timer> mTimer;
  std::chrono::duration<double> mElapsedTime;
};  // TODO: do shit
}  // namespace benchtools