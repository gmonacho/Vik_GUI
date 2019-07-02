cmake_minimum_required(VERSION 3.10)
project(Vik_Wrap)

if (UNIX)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
elseif (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

add_library(${PROJECT_NAME} SHARED
       src/Init.cpp
       src/Window.cpp
       src/Renderer.cpp
       src/GeometricObject.cpp
       src/Event.cpp
       src/Rect.cpp
       src/Point.cpp
       src/Line.cpp
       src/Font.cpp
       src/Exception.cpp
       src/collision.cpp
       src/Circle.cpp
       src/Polygon.cpp
       include/Init.h
       include/Window.h
       include/Renderer.h
       include/GeometricObject.h
       include/Event.h
       include/Rect.h src/Texture.cpp
       include/Texture.h
       include/Point.h
       include/Line.h
       include/Font.h
       include/Exception.h
       include/collision.h
       include/Circle.h
       include/Polygon.h)

# add_executable(${PROJECT_NAME} src/main.cpp
#         src/Init.cpp
#         src/Window.cpp
#         src/Renderer.cpp
#         src/Event.cpp
#         src/GeometricObject.cpp
#         src/Rect.cpp
#         src/Point.cpp
#         src/Line.cpp
#         src/Font.cpp
#         src/Exception.cpp
#         src/collision.cpp
#         src/Circle.cpp
#         src/Polygon.cpp
#         include/Init.h
#         include/Window.h
#         include/Renderer.h
#         include/Event.h
#         include/Rect.h src/Texture.cpp
#         include/Texture.h
#         include/GeometricObject.h
#         include/Point.h
#         include/Line.h
#         include/Font.h
#         include/Exception.h
#         include/collision.h
#         include/Circle.h
#         include/Polygon.h)

if (MINGW)
        set(LIBRARIES -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)
elseif (UNIX)
        set(LIBRARIES ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
endif()

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})