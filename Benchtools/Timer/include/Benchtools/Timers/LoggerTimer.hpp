#pragma once
#include "Benchtools/Core/Time.hpp"
#include <Benchtools/Timers/BaseTimer.hpp>
#include <Benchtools/Timers/WatchTimer.hpp>

namespace benchtools {

class LoggingTimer : public BaseTimer {
public:
  explicit LoggingTimer() : mTimer(WatchTimer()) { mTimer.start(); };

  virtual ~LoggingTimer() override;

  virtual void start() override;

  virtual void stop() override;

private:
  virtual std::chrono::duration<double> currentElapsed() override;

private:
  WatchTimer mTimer{};
  time_unit mUnit{time_unit::seconds};
};
}  // namespace benchtools