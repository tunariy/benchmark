#pragma once
#include <Benchtools/Timers/Timer.hpp>
#include <Benchtools/Timers/WatchTimer.hpp>

namespace benchtools {

class ScopedTimer : public Timer {
public:
  explicit ScopedTimer() : mTimer(WatchTimer()) {
    mTimer.start();
    mTimer.setUnit(time_unit::milliseconds);
  };

  explicit ScopedTimer(time_unit unit) : mTimer(WatchTimer()) {
    mTimer.start();
    mTimer.setUnit(unit);
  };

  virtual ~ScopedTimer() override;

private:
  virtual void start() override;

  virtual void stop() override;

  virtual std::chrono::duration<double> currentElapsed() override;

private:
  WatchTimer mTimer{};
};
}  // namespace benchtools