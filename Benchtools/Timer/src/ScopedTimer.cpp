#include "Benchtools/Logger/Logger.hpp"
#include <Benchtools/Timers/ScopedTimer.hpp>
#include <string>

namespace benchtools {

ScopedTimer::~ScopedTimer() {
  mTimer.stop();
  std::string res = std::to_string(mTimer.mElapsedTime.count()) + benchtools::format(mUnit);
  TRACE(res);
}

void ScopedTimer::start() {}

void ScopedTimer::stop() {
  mTimer.mElapsedTime = this->currentElapsed();
}

[[nodiscard]] std::chrono::duration<double> ScopedTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mTimer.mStartPoint;
}

}  // namespace benchtools