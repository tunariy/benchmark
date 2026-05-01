#include <benchtools/Core/Time.hpp>
#include <benchtools/Timers/ClockTimer.hpp>

namespace benchtools {

void ClockTimer::start() {
    mStart = std::clock();
    mRunning = true;
}
void ClockTimer::stop() {
    mEnd = std::clock();
    mRunning = false;
}

void ClockTimer::reset(bool) {
    mStart = 0;
    mEnd = 0;
}

[[nodiscard]] Duration ClockTimer::duration(time_unit durationType) noexcept {
    clock_t end = mRunning ? std::clock() : mEnd;
    return durationCast(this->currentElapsed(), durationType);
}

[[nodiscard]] std::chrono::duration<double> ClockTimer::currentElapsed() noexcept {
    return std::chrono::duration<double>(static_cast<double>(std::clock() - mStart) /
                                         CLOCKS_PER_SEC);
};

}  // namespace benchtools