cmake_minimum_required(VERSION 3.10)
project (Restaurant_Simulator_COS214_Group_Project)

find_package(GTest REQUIRED)

file(GLOB sources
     "../src/*.h"
     "../src/*.cpp"
     "../src/*/*.h"
     "../src/*/*.cpp"
     "main_test.cpp"
)

list(FILTER sources EXCLUDE REGEX ".*main\\.cpp$")

# main_test becauce test is apparently reserved when using CTest
add_executable(
  main_test
  ${sources}
)

target_link_libraries(
  main_test
  ${GTEST_LIBRARIES}
)

enable_testing()
add_test(add main_test)

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})
# 
# file(GLOB test
#      "../src/*.h"
#      "../src/*.cpp"
#      "*.cpp"
# )
# 
# list(FILTER test EXCLUDE REGEX ".*main\\.cpp$")
# add_executable(test ${test})
# target_link_libraries(test ${GTEST_LIBRARIES} pthread)
# set(CMAKE_BUILD_TYPE Debug)