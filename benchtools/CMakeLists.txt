cmake_minimum_required(VERSION 3.20)

include(FetchContent)
include(CTest)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
)
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "" FORCE)
set(SPDLOG_HEADER_ONLY OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(spdlog)

add_subdirectory(Core)
add_subdirectory(Logger)
add_subdirectory(Timer)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Test/CMakeLists.txt)
    if(BUILD_TESTING)
        add_subdirectory(Test)
    endif()
endif()