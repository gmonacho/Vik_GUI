cmake_minimum_required(VERSION 3.14)
project(Vik_Wrap)

if (UNIX)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
elseif (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

#set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/mingw/i686-w64-mingw32)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
#set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/mingw/i686-w64-mingw32)
#set(SDL2_image_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2/mingw/i686-w64-mingw32)
#set(SDL2_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x86/SDL2main.lib;\
#${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x86/SDL2.lib;\
#${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x86/SDL2_ttf.lib;\
#${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x86/SDL2_image.lib")

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/SDL2/include)
#add_library(${PROJECT_NAME} SHARED
#        src/Init.cpp
#        src/Window.cpp
#        src/Renderer.cpp
#        src/Event.cpp
#        src/Rect.cpp
#        src/Point.cpp
#        src/Line.cpp
#        src/Font.cpp
#        include/Window.h
#        include/Renderer.h
#        include/Event.h
#        include/Rect.h src/Texture.cpp
#        include/Texture.h
#        include/Point.h
#        include/Line.h
#        include/Font.h)
add_executable(${PROJECT_NAME}  main.cpp
        src/Init.cpp
        src/Window.cpp
        src/Renderer.cpp
        src/Event.cpp
        src/Rect.cpp
        src/Point.cpp
        src/Line.cpp
        src/Font.cpp
        include/Window.h
        include/Renderer.h
        include/Event.h
        include/Rect.h src/Texture.cpp
        include/Texture.h
        include/Point.h
        include/Line.h
        include/Font.h src/Exception.cpp include/Exception.h)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)