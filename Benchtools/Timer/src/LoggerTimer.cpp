#include "Benchtools/Logger/Logger.hpp"
#include <Benchtools/Timers/LoggerTimer.hpp>
#include <string>

namespace benchtools {

LoggingTimer::~LoggingTimer() {
  // TODO: should it log when it goes out of timer? fuck might have to wrap timers in this shit as well
  // mTimer.stop();
  // std::string res =
  //   std::to_string(mTimer.mElapsedTime.count()) + benchtools::format(mUnit);
  // TRACE(res);
}

void LoggingTimer::start() {}

void LoggingTimer::stop() {
  mTimer.mElapsedTime = currentElapsed();
  std::string res =
    std::to_string(mTimer.mElapsedTime.count()) + benchtools::format(mUnit);
  TRACE(res);
}

[[nodiscard]] std::chrono::duration<double> LoggingTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mTimer.mStartPoint;
}

}  // namespace benchtools