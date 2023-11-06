cmake_minimum_required(VERSION 3.10)
project (Restaurant_Simulator_COS214_Group_Project)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB src
     "../src/*.h"
     "../src/*.cpp"
     "../src/*/*.h"
     "../src/*/*.cpp"
)

list(FILTER src EXCLUDE REGEX ".*main\\.cpp$")

add_executable(main ${src})
set(CMAKE_BUILD_TYPE Debug)
