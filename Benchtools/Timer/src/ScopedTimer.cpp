#include "Benchtools/Core/Time.hpp"
#include "Benchtools/Timers/BaseTimer.hpp"
#include <Benchtools/Timers/ScopedTimer.hpp>
#include <chrono>

namespace benchtools {

ScopedTimer::ScopedTimer(BaseTimer& timer) : mTimer(&timer) {
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
