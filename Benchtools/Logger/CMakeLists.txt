add_library(Logger STATIC
    src/Logger.cpp
)

target_include_directories(Logger
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(Logger PUBLIC spdlog::spdlog fmt::fmt)

target_compile_features(Logger PRIVATE cxx_std_20)