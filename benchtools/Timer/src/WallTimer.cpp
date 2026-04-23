#include <benchtools/Core/Time.hpp>
#include <benchtools/Timers/WallTimer.hpp>

namespace benchtools {

WallTimer::~WallTimer() {}

void WallTimer::start() {
  mStartPoint = std::chrono::high_resolution_clock::now();
  mIsRunning = true;
}

void WallTimer::stop() {
  if (mIsRunning) {
    mElapsedTime += std::chrono::high_resolution_clock::now() - mStartPoint;
    mIsRunning = false;
  }
}

void WallTimer::reset() {
  mElapsedTime = default_duration;
  mIsRunning = false;
}

[[nodiscard]] Duration WallTimer::duration(time_unit durationType) {
  return durationCast(mElapsedTime, durationType);
}

[[nodiscard]] std::chrono::duration<double> WallTimer::currentElapsed() {
  return std::chrono::high_resolution_clock::now() - mStartPoint;
}

}  // namespace benchtools