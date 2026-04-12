add_executable(benchmark_app main.cpp)

target_link_libraries(benchmark_app
    PRIVATE Timer
)