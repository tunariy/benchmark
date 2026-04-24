#include "benchtools/Core/Time.hpp"
#include "benchtools/Timers/BaseTimer.hpp"
#include <benchtools/Timers/ScopedTimer.hpp>
#include <chrono>

namespace benchtools {

ScopedTimer::ScopedTimer(BaseTimer& timer) : mTimer(&timer) {
  mTimer->reset();
  mTimer->start();
}

void ScopedTimer::start() {}

void ScopedTimer::stop() {}

ScopedTimer::~ScopedTimer() {
  mTimer->stop();
}

Duration ScopedTimer::duration(time_unit durationType) {
  return mTimer->duration();
};

std::chrono::duration<double> ScopedTimer::currentElapsed() {
  return default_duration;
}
};  // namespace benchtools
