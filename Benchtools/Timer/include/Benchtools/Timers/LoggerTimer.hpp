#pragma once
#include <Benchtools/Timers/BaseTimer.hpp>
#include <Benchtools/Timers/WatchTimer.hpp>

namespace benchtools {

class LoggingTimer : public BaseTimer {
public:
  explicit LoggingTimer() : mTimer(WatchTimer()) {
    mTimer.start();
    mTimer.setUnit(time_unit::milliseconds);
  };

  explicit LoggingTimer(time_unit unit) : mTimer(WatchTimer()) {
    mTimer.start();
    mTimer.setUnit(unit);
  };

  virtual ~LoggingTimer() override;

private:
  virtual void start() override;

  virtual void stop() override;

  virtual std::chrono::duration<double> currentElapsed() override;

private:
  WatchTimer mTimer{};
};
}  // namespace benchtools