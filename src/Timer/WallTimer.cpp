#include <benchtools/Core/Time.hpp>
#include <benchtools/Timers/WallTimer.hpp>

namespace benchtools {

WallTimer::~WallTimer() {}

void WallTimer::start() {
    m_Start = std::chrono::high_resolution_clock::now();
    m_Running = true;
}

void WallTimer::stop() {
    if (m_Running) {
        m_ElapsedTime += std::chrono::high_resolution_clock::now() - m_Start;
        m_Running = false;
    }
}

void WallTimer::reset(bool reset) {
    if (reset) m_ElapsedTime = default_duration;
    m_Running = false;
}

Duration WallTimer::duration(time_unit durationType) {
    return durationCast(m_ElapsedTime, durationType);
}

std::chrono::duration<double> WallTimer::currentElapsed() {
    return std::chrono::high_resolution_clock::now() - m_Start;
}

}  // namespace benchtools