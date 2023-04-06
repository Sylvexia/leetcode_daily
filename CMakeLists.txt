cmake_minimum_required(VERSION 3.0.0)
project(test)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(test test.cpp)
add_executable(num_closed num_closed_island_1254.cpp)