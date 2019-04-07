cmake_minimum_required(VERSION 3.13)
project(Vik_Wrap)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp src/VRA_init.cpp src/VRA_Window.cpp include/VRA_Window.h src/VRA_Renderer.cpp include/VRA_Renderer.h)
target_link_libraries(${PROJECT_NAME} -lSDL2main -lSDL2)