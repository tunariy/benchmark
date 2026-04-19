#pragma once

#include <Benchtools/Core/Time.hpp>
#include <Benchtools/Timers/BaseTimer.hpp>
#include <memory>

namespace benchtools {

class ScopedTimer {

  std::unique_ptr<BaseTimer> mTimer;
};
};  // namespace benchtools