#include <Benchtools/Timers/BaseTimer.hpp>

namespace benchtools {

BaseTimer::~BaseTimer() {}

void BaseTimer::setUnit(time_unit unit) {
  mUnit = unit;
};

}  // namespace benchtools