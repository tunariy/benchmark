#include <benchtools/Logger/Logger.hpp>
#include <benchtools/Timers/ScopedTimer.hpp>
#include <benchtools/Timers/WallTimer.hpp>
#include <iostream>

using namespace benchtools;
using enum time_unit;

int main() {
  INFO("{} {}", 1, 1);
  WallTimer timer{};
  {
    ScopedTimer scop(timer);
    std::cin.get();
  }
  std::clog << timer.duration(seconds).str() << std::endl;
  {
    ScopedTimer scop(timer);
    std::cin.get();
  }
  std::clog << timer.duration(seconds).str() << std::endl;
  {
    ScopedTimer scop(timer);
    std::cin.get();
  }
  std::clog << timer.duration(seconds).str() << std::endl;
  timer.reset();
}