#include <benchtools/Logger/Logger.hpp>
#include <benchtools/Timers/LoggerTimer.hpp>
#include <string>

namespace benchtools {

LoggingTimer::~LoggingTimer() {
  mTimer.stop();
  TRACE(std::to_string(mTimer.mElapsedTime.count()) + benchtools::format(mUnit));
}

void LoggingTimer::start() {
  mTimer.start();
}

void LoggingTimer::stop() {
  mTimer.stop();
  mTimer.mElapsedTime = currentElapsed();
  std::string res =
    std::to_string(mTimer.mElapsedTime.count()) + benchtools::format(mUnit);
  TRACE(res);
}

[[nodiscard]] std::chrono::duration<double> LoggingTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mTimer.mStartPoint;
}

}  // namespace benchtools