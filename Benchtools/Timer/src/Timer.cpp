#include <Benchtools/Timer.hpp>

namespace benchtools {

Timer::~Timer() {}

void Timer::setUnit(time_unit unit) {
  mUnit = unit;
};

}  // namespace benchtools