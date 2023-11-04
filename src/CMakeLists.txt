cmake_minimum_required(VERSION 3.10)
project (Restaurant_Simulator_COS214_Group_Project)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB src
     "*.h"
     "*.cpp"
     "Bill/*.h"
     "Booking/*.h"
     "Builder/*.h"
     "ChainOfResponsibility/*.h"
     "List/*.h"
     "Staff/*.h"
     "State/*.h"
     "Tab/*.h"
     "Table/*.h"
     "Bill/*.cpp"
     "Booking/*.cpp"
     "Builder/*.cpp"
     "ChainOfResponsibility/*.cpp"
     "List/*.cpp"
     "Staff/*.cpp"
     "State/*.cpp"
     "Tab/*.cpp"
     "Table/*.cpp"
)

add_executable(main ${src})
set(CMAKE_BUILD_TYPE Debug)
