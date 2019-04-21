cmake_minimum_required(VERSION 3.13)
project(Vik_Wrap)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME}  main.cpp
                                src/VRA_init.cpp
                                src/VRA_Window.cpp
                                src/VRA_Renderer.cpp
                                src/VRA_Event.cpp
                                src/VRA_Rect.cpp
                                src/VRA_Point.cpp
                                src/VRA_Line.cpp
                                include/VRA_Window.h
                                include/VRA_Renderer.h
                                include/VRA_Event.h
                                include/VRA_Rect.h src/VRA_Texture.cpp
                                include/VRA_Texture.h
                                include/VRA_Point.h
                                include/VRA_Line.h src/VRA_Font.cpp include/VRA_Font.h)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image SDL2::TTF)