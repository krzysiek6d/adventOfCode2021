cmake_minimum_required(VERSION 3.14)
project(advent)
include(FetchContent)
set(CMAKE_CXX_STANDARD 20)

Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(advent_01)
add_subdirectory(advent_01_p2)
add_subdirectory(advent_02)
add_subdirectory(advent_02_p2)
add_subdirectory(advent_03)
add_subdirectory(advent_03_p2)
add_subdirectory(advent_04)
add_subdirectory(advent_04_p2)
add_subdirectory(advent_05)
add_subdirectory(advent_05_p2)

add_subdirectory(advent_09)
add_subdirectory(advent_09_p2)