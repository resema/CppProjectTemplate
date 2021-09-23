cmake_minimum_required(VERSION 3.12)

set(PROJECT "Benchmarking")

project("${PROJECT}_Project" VERSION 1.2.3 LANGUAGES CXX)

# Global variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable a Code Coverage build." OFF)
option(ENABLE_BENCHMARKS "Enable a Benchmarks build." ON)

# Cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
if (ENABLE_TESTING)
    include(CTest)
endif()

# Project/Lib Names
set(LIBRARY_NAME    "${PROJECT}_MyLib")
set(EXECUTABLE_NAME "${PROJECT}_Executable")
set(TEST_MAIN       "${PROJECT}_UnitTests")

# Configuration Files
configure_file("${PROJECT_SOURCE_DIR}/inc/ProjectConfig.h.in"
               "${PROJECT_SOURCE_DIR}/inc/ProjectConfig.h" @ONLY)

# Add Conan Libraries
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()      

# Add external Libraries
add_subdirectory("${PROJECT_SOURCE_DIR}/ext")

# Add Libraries
add_subdirectory("${PROJECT_SOURCE_DIR}/src")

# Add executable
add_subdirectory("${PROJECT_SOURCE_DIR}/app")

# Add unit tests
if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory("${PROJECT_SOURCE_DIR}/tests/")
endif()

# Add benchmark tests
if (ENABLE_BENCHMARKS)
    add_subdirectory("${PROJECT_SOURCE_DIR}/benchmarks/")
endif()