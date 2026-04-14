#pragma once
#include "Benchtools/Time.hpp"
#include "Benchtools/Timers/Timer.hpp"

#include <atomic>
#include <chrono>
#include <ctime>

namespace benchtools {

class CpuTimer : public Timer {
public:
  void start() override;

  void stop() override;

  [[nodiscard]] std::chrono::duration<double> timeElapsed(time_unit durationType = time_unit::seconds) override;

  [[nodiscard]] std::chrono::duration<double> currentElapsed() override;

private:
  std::clock_t mStart = 0;
  std::clock_t mEnd = 0;
  std::atomic<bool> mRunning = false;
};

}  // namespace benchtools