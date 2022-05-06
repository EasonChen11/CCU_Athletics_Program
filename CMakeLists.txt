cmake_minimum_required(VERSION 3.21)
project(CCU_Athletics_Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(DP1_1 DP1/Prefix_Sum.cpp)
add_executable(DP1_2_normal DP1/pack.cpp)
add_executable(DP1_2_bouns DP1/pack_bouns.cpp)
add_executable(DP1_3_bottom_up DP1/Coin_bottom_up.cpp)

add_executable(DP2_1_LCS DP2/LCS.cpp)
add_executable(DP2_2_LIS DP2/LIS.cpp)
