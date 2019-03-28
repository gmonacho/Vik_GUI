cmake_minimum_required(VERSION 3.13)
project(Vik_GUI)

set(CMAKE_CXX_STANDARD 17)

set(SRC main.cpp)

#add_library(Vik_GUI main.cpp)
add_executable(Vik_GUI  ${SRC})