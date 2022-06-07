cmake_minimum_required(VERSION 3.22)
project(BrazzGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(BrazzGUI src/main.cpp)
