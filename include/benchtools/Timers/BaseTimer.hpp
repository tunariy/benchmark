#pragma once

#include <benchtools/Core/Time.hpp>

#include <chrono>

namespace benchtools {

class WallTimer;

using Timer = WallTimer;

/**
 * @brief Base class for timers, used as a blueprint for what a timer should do
 */
class BaseTimer {
  public:
    BaseTimer() = default;

    virtual ~BaseTimer();

    /**
     * @brief Pure virtual function that will define how Timer should act on start()
     */
    virtual void start() = 0;

    /**
     * @brief Pure virtual function that will define how Timer should act on stop()
     */
    virtual void stop() = 0;

    /**
     * @brief Resets the timer duration
     */
    virtual void reset(bool) = 0;

    /**
     * @brief Gets the duration in the respective timeunit
     *
     * @param durationType
     * @return Duration
     */
    [[nodiscard]] virtual Duration
    duration(time_unit durationType = time_unit::seconds) noexcept {
        return durationCast(default_duration, time_unit::seconds);
    };

  private:
    /**
     * @brief Pure virtual function for getting elapsed duration since at that moment
     *
     * @return std::chrono::duration<double>
     */
    virtual std::chrono::duration<double> currentElapsed() noexcept = 0;
};

}  // namespace benchtools