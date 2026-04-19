#include <Benchtools/Timers/CPUTimer.hpp>

namespace benchtools {

void CpuTimer::start() {
  mStart = std::clock();
  mRunning = true;
}
void CpuTimer::stop() {
  mEnd = std::clock();
  mRunning = false;
}

[[nodiscard]] std::chrono::duration<double>
CpuTimer::timeElapsed(time_unit durationType) {
  clock_t end = mRunning ? std::clock() : mEnd;
  return std::chrono::duration<double>(static_cast<double>(end - mStart) /
                                       CLOCKS_PER_SEC);
}

[[nodiscard]] std::chrono::duration<double> CpuTimer::currentElapsed() {
  return std::chrono::duration<double>(static_cast<double>(std::clock() - mStart) /
                                       CLOCKS_PER_SEC);
};

}  // namespace benchtools