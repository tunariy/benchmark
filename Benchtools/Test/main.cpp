#include "Benchtools/Core/Time.hpp"
#include <Benchtools/Core/FileStream.hpp>
#include <Benchtools/Logger/Logger.hpp>
#include <Benchtools/Timers.hpp>

#include <iostream>

using namespace benchtools;

int main() {
  WatchTimer timer{};
  {
    ScopedTimer scop(timer);
    std::cin.get();
  }
  std::clog << timer.duration(time_unit::nanoseconds).str() << std::endl;
}