#include <benchtools/Core/Time.hpp>
#include <benchtools/Timers/ClockTimer.hpp>

namespace benchtools {

void CpuTimer::start() {
  mStart = std::clock();
  mRunning = true;
}
void CpuTimer::stop() {
  mEnd = std::clock();
  mRunning = false;
}

[[nodiscard]] Duration CpuTimer::duration(time_unit durationType) {
  clock_t end = mRunning ? std::clock() : mEnd;
  return durationCast(
    std::chrono::duration<double>(static_cast<double>(end - mStart) / CLOCKS_PER_SEC),
    durationType);
}

[[nodiscard]] std::chrono::duration<double> CpuTimer::currentElapsed() {
  return std::chrono::duration<double>(static_cast<double>(std::clock() - mStart) /
                                       CLOCKS_PER_SEC);
};

}  // namespace benchtools