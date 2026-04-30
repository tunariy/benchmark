#include <benchtools/Timers.hpp>
#include <iostream>

using namespace benchtools;
using enum time_unit;

int main() {
#if 0
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
#elif 1
    ClockTimer timer{};
    {
        LoggingTimer login{timer, nanoseconds};
        std::cin.get();
    }
    {
        LoggingTimer login{timer, nanoseconds};
        std::cin.get();
        login.stop();
    }
#endif
}