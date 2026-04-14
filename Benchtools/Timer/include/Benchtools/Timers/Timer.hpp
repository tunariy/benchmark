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

  virtual std::chrono::duration<double> timeElapsed(time_unit durationType = time_unit::seconds) {
    return std::chrono::duration<double>::zero();
  };

  void setUnit(time_unit unit);

private:
  virtual std::chrono::duration<double> currentElapsed() = 0;

protected:
  time_unit mUnit = time_unit::seconds;
};

}  // namespace benchtools