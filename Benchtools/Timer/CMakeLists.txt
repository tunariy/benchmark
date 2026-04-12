file(GLOB TIMER_SOURCES
    "src/*.cpp"
)

add_library(Timer STATIC ${TIMER_SOURCES})

target_include_directories(Timer
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(Timer
    PUBLIC Logger
)

target_compile_features(Timer PRIVATE cxx_std_20)