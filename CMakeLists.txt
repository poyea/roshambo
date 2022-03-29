# For Roshambo build
cmake_minimum_required(VERSION 3.12..3.16)

project(roshambo
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Paper Scissors Rock")

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(ENABLE_DEVELOPER_MODE TRUE CACHE BOOL "Enable 'developer mode'")

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cc)
add_executable(Roshambo ${SRC_FILES})

# For Roshambo test build
# See README.md for details
if(TESTS)
    enable_testing()
    message("-- Building Tests")
    add_subdirectory(tests)
endif()