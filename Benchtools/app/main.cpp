#include <Benchtools/ScopedTimer.hpp>
#include <Benchtools/Timer.hpp>
#include <Benchtools/WatchTimer.hpp>
#include <iostream>

int main() {
  benchtools::WatchTimer Timer;
  Timer.start();
  std::cin.get();
  Timer.stop();
  std::clog << Timer.timeElapsed() << std::endl;
  benchtools::ScopedTimer t2;
  std::cin.get();
  std::clog << benchtools::gLastDuration;
}