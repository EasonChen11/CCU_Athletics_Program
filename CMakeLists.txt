cmake_minimum_required(VERSION 3.21)
project(CCU_Athletics_Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph1_A graph1/graph.cpp)
add_executable(graph1_B graph1/DFS.cpp)
add_executable(graph1_C graph1/Connected_Components.cpp)
add_executable(graph1_D graph1/BFS.cpp)
