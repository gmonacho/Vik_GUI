cmake_minimum_required(VERSION 3.14)
project(Vik_Wrap)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} MODULE
       src/Init.cpp
       src/Window.cpp
       src/Renderer.cpp
       src/Event.cpp
       src/Rect.cpp
       src/Point.cpp
       src/Line.cpp
       src/Font.cpp
       src/Exception.cpp
       include/Init.h
       include/Window.h
       include/Renderer.h
       include/Event.h
       include/Rect.h src/Texture.cpp
       include/Texture.h
       include/Point.h
       include/Line.h
       include/Font.h
       include/Exception.h)

# add_executable(${PROJECT_NAME} src/main.cpp
#         src/Init.cpp
#         src/Window.cpp
#         src/Renderer.cpp
#         src/Event.cpp
#         src/Rect.cpp
#         src/Point.cpp
#         src/Line.cpp
#         src/Font.cpp
#         src/Exception.cpp
#         include/Init.h
#         include/Window.h
#         include/Renderer.h
#         include/Event.h
#         include/Rect.h src/Texture.cpp
#         include/Texture.h
#         include/Point.h
#         include/Line.h
#         include/Font.h
#         include/Exception.h)

target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)