add_library(Logger STATIC
    src/Logger.cpp
)
add_library(Benchtools::Logger ALIAS Logger)

target_include_directories(Logger
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(Logger PRIVATE $<BUILD_INTERFACE:spdlog::spdlog>)

target_compile_features(Logger PRIVATE cxx_std_20)

########### EXPORT ########### 
install(TARGETS Logger EXPORT BenchtoolsTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
install(DIRECTORY include/ DESTINATION include)