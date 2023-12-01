cmake_minimum_required(VERSION 3.26)
project(aoc_2k23)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(SolveUtils)

file(GLOB_RECURSE SOLUTIONS ${PROJECT_SOURCE_DIR}/Day*/*.cpp)
message(${SOLUTIONS})
add_executable(aoc_2k23 main.cpp ${SOLUTIONS})

target_link_libraries(aoc_2k23 PUBLIC SolveUtils)

target_include_directories(aoc_2k23 PUBLIC "${PROJECT_SOURCE_DIR}/SolveUtils")
