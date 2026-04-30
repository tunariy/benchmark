# src/CMakeLists.txt
include(FetchContent)

find_package(spdlog QUIET)
if(NOT spdlog_FOUND)
    message(STATUS "spdlog not found – fetching from GitHub")
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.14.1
    )
    FetchContent_MakeAvailable(spdlog)
endif()

######## CORE ######## 
add_library(Core
    Core/FileStream.cpp
    Core/Time.cpp
)
target_include_directories(Core
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_compile_features(Core PUBLIC cxx_std_20)

######## LOGGER ######## 
add_library(Logger
    Logger/FileLogger.cpp
)
target_include_directories(Logger
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_compile_features(Logger PUBLIC cxx_std_20)
target_link_libraries(Logger PUBLIC 
    Core
    spdlog::spdlog)

######## TIMER ######## 
add_library(Timer
    Timer/BaseTimer.cpp
    Timer/ClockTimer.cpp
    Timer/LoggerTimer.cpp
    Timer/ScopedTimer.cpp
    Timer/WallTimer.cpp
)
target_include_directories(Timer
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
target_compile_features(Timer PUBLIC cxx_std_20)
target_link_libraries(Timer PUBLIC Logger)


######## TESTING ######## 
option(TESTING "Build test programs" OFF)

if(TESTING)
    add_executable(benchtools_testing
        Test/Test.cpp
    )
    target_link_libraries(benchtools_testing PRIVATE Timer)
    target_compile_features(benchtools_testing PRIVATE cxx_std_20)
endif()