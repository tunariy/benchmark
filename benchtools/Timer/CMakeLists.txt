file(GLOB TIMER_SOURCES
    "src/*.cpp"
)

add_library(Timer STATIC ${TIMER_SOURCES})
add_library(Benchtools::Timer ALIAS Timer)

target_include_directories(Timer
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(Timer
    PUBLIC Benchtools::Logger Benchtools::Core
)

target_compile_features(Timer PRIVATE cxx_std_20)


########### EXPORT ###########  
install(TARGETS Timer EXPORT BenchtoolsTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
install(DIRECTORY include/ DESTINATION include)