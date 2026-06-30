cmake_minimum_required(VERSION 3.10)
project(MetroPlanner)
set(CMAKE_CXX_STANDARD 11)
add_executable(metro_planner main.cpp MetroGraph.cpp)