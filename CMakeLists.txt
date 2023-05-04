cmake_minimum_required(VERSION 3.0.0)
project(test)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(test dota_2_senate_649.cpp)