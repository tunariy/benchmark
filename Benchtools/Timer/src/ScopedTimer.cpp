#include <Benchtools/ScopedTimer.hpp>

namespace benchtools {

ScopedTimer::~ScopedTimer() {
  mTimer.stop();
  benchtools::gLastDuration = mTimer.timeElapsed(mUnit);
}

void ScopedTimer::start() {}

void ScopedTimer::stop() {}

std::chrono::duration<double> ScopedTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mTimer.mStartPoint;
}

}  // namespace benchtools