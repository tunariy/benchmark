#pragma once
#include "Benchtools/Time.hpp"
#include <Benchtools/Timers/Timer.hpp>
#include <atomic>

namespace benchtools {

class ScopedTimer;

class WatchTimer : public Timer {
  using clock = std::chrono::high_resolution_clock;
  using time_point = clock::time_point;

public:
  WatchTimer();

  virtual ~WatchTimer() override;

  void start() override;

  void stop() override;

  void reset();
  
  std::chrono::duration<double> timeElapsed(time_unit durationType = time_unit::seconds) override;

public:
  friend class ScopedTimer;

private:
  virtual std::chrono::duration<double> currentElapsed() override;

private:
  time_point mStartPoint;
  std::chrono::duration<double> mElapsedTime{std::chrono::duration<double>::zero()};
  std::atomic<bool> mIsRunning{0};
};

}  // namespace benchtools