cmake_minimum_required(VERSION 3.20)
project(benchtools VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(benchtools)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/benchtools/cmake/BenchtoolsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/BenchtoolsConfig.cmake
    INSTALL_DESTINATION lib/cmake/Benchtools
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/BenchtoolsConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(EXPORT BenchtoolsTargets
    FILE BenchtoolsTargets.cmake
    NAMESPACE Benchtools::                   
    DESTINATION lib/cmake/Benchtools
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/BenchtoolsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/BenchtoolsConfigVersion.cmake
    DESTINATION lib/cmake/Benchtools
)