#pragma once
#include <Benchtools/Time.hpp>
#include <chrono>

namespace benchtools {

class Timer {
public:
  Timer() = default;

  virtual ~Timer();

  virtual void start() = 0;

  virtual void stop() = 0;

  virtual std::chrono::duration<double> currentElapsed() = 0;

  void setUnit(time_unit unit);

protected:
  time_unit mUnit = time_unit::miliseconds;
};

}  // namespace benchtools