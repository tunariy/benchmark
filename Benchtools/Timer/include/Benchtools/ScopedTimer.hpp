#pragma once
#include <Benchtools/Timer.hpp>
#include <Benchtools/WatchTimer.hpp>

namespace benchtools {

// TODO: Find a way to store a global state properly
static std::chrono::duration<double> gLastDuration{std::chrono::duration<double>::zero()};

class ScopedTimer : public Timer {
public:
  ScopedTimer() : mTimer(WatchTimer()) {
    mTimer.start();
    setUnit(time_unit::miliseconds);
  };

  ScopedTimer(time_unit unit) : mTimer(WatchTimer()) {
    mTimer.start();
    setUnit(unit);
  };

  virtual void start() override;

  virtual void stop() override;

  virtual ~ScopedTimer() override;

private:
  virtual std::chrono::duration<double> currentElapsed() override;

private:
  WatchTimer mTimer;
};
}  // namespace benchtools