#include <Benchtools/Logger/Logger.hpp>
#include <Benchtools/Timers/CPUTimer.hpp>
#include <Benchtools/Timers/ScopedTimer.hpp>
#include <Benchtools/Timers/WatchTimer.hpp>
#include <iostream>

int main() {
  TRACE("BLM");
  benchtools::WatchTimer t;
  t.start();
  std::cin.get();
  t.stop();
  benchtools::Timer* cputim = new benchtools::CpuTimer();

  cputim->start();
  INFO(t.timeElapsed().count());
  /*
  {
    benchtools::ScopedTimer t2;
    std::cin.get();
    }
    */
  std::cin.get();
  cputim->stop();
  INFO(cputim->timeElapsed().count());
  delete cputim;
}