add_executable(test_app example.cpp)

target_link_libraries(test_app PRIVATE 
    Timer Logger spdlog::spdlog
)

add_test(NAME MyLibraryTests COMMAND my_library_tests)