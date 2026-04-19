#include <Benchtools/Core/FileStream.hpp>

#include <Benchtools/Timers/Timers.hpp>

#include <Benchtools/Logger/Logger.hpp>

#include <iostream>

int main() {
#if 1
  TRACE("");
  benchtools::WatchTimer t;
  t.start();
  std::cin.get();
  t.stop();
  benchtools::BaseTimer* cputim = new benchtools::CpuTimer();

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
#endif
}