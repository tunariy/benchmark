#include <benchtools/Timers/ScopedTimer.hpp>
#include <benchtools/Timers/WallTimer.hpp>
#include <iostream>

using namespace benchtools;
using enum time_unit;

int main() {
  WallTimer timer{};
  {
    ScopedTimer scop(timer);
    std::cin.get();
  }
  std::clog << timer.duration(nanoseconds).str() << std::endl;
}