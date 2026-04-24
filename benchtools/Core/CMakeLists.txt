file(GLOB FILE_SOURCES
    "src/*.cpp"
)

add_library(Core STATIC ${FILE_SOURCES})
add_library(Benchtools::Core ALIAS Core)

target_include_directories(Core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(Core
    PUBLIC)

target_compile_features(Core PUBLIC cxx_std_20)

########### EXPORT ########### 
install(TARGETS Core
    EXPORT BenchtoolsTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)