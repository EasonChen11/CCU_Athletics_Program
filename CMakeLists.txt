cmake_minimum_required(VERSION 3.21)
project(CCU_Athletics_Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph1_A graph1/graph.cpp)
add_executable(graph1_B graph1/DFS.cpp)
add_executable(graph1_C_union_find graph1/Connected_Components_union_find.cpp)
add_executable(graph1_C_BFS graph1/Connected_Components_BFS.cpp)
add_executable(graph1_C_DFS graph1/Connected_Components_DFS.cpp)
add_executable(graph1_D graph1/BFS.cpp)

add_executable(graph2_A graph2/Dijkstra.cpp)
add_executable(graph2_B graph2/RenaiCirculation_Bellman-Ford.cpp)
add_executable(graph2_C graph2/Floyd_Warshall.cpp)
