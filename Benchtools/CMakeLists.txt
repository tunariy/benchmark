cmake_minimum_required(VERSION 3.20)
project(Benchtools VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.0
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.12.0
)
set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "" FORCE)   # Use external fmt
set(SPDLOG_HEADER_ONLY OFF CACHE BOOL "" FORCE)   # Compiled mode
FetchContent_MakeAvailable(spdlog)

add_subdirectory(Core)
add_subdirectory(Logger)
add_subdirectory(Timer)

# add_subdirectory(File)

# idk
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/App/CMakeLists.txt)
    add_subdirectory(App)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Test/CMakeLists.txt)
    add_subdirectory(Test)
endif()