#include <Benchtools/Time.hpp>
#include <Benchtools/WatchTimer.hpp>
#include <chrono>

namespace benchtools {

WatchTimer::WatchTimer() {}

WatchTimer::~WatchTimer() {}

void WatchTimer::start() {
  mStartPoint = std::chrono::high_resolution_clock::now();
  mIsRunning = true;
}

void WatchTimer::stop() {
  if (mIsRunning) {
    mElapsedTime += std::chrono::high_resolution_clock::now() - mStartPoint;
    mIsRunning = false;
  }
}

void WatchTimer::reset() {
  mElapsedTime = std::chrono::duration<double>::zero();
  mIsRunning = false;
}

std::chrono::duration<double> WatchTimer::timeElapsed(time_unit durationType) {
  return durationCast(mElapsedTime, durationType);
}

std::chrono::duration<double> WatchTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mStartPoint;
}

}  // namespace benchtools