#pragma once
#include "Benchtools/Core/Time.hpp"
#include <Benchtools/Timers/BaseTimer.hpp>
#include <atomic>

namespace benchtools {

class LoggingTimer;

class WatchTimer : public BaseTimer {
  using clock = std::chrono::high_resolution_clock;
  using time_point = clock::time_point;

public:
  WatchTimer() = default;

  virtual ~WatchTimer() override;

  virtual void start() override;

  virtual void stop() override;

  void reset();

  virtual Duration duration(time_unit durationType) override;

public:
  friend class LoggingTimer;

private:
  virtual std::chrono::duration<double> currentElapsed() override;

private:
  time_point mStartPoint;
  std::chrono::duration<double> mElapsedTime{default_duration};
  std::atomic<bool> mIsRunning{0};
};

}  // namespace benchtools