cmake_minimum_required(VERSION 3.0.0)
project(test)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

add_executable(test rm_max_num_keep_graph_trav_1579.cpp)