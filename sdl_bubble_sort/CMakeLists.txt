cmake_minimum_required(VERSION 3.15)
project(SDL_bubble_sort)

set(SDL_DIR C:/dev/i686-w64-mingw32)
set(SDL2_LIB_DIR ${SDL_DIR}/lib)
include_directories(${SDL_DIR}/include)

add_definitions(-DSDL_MAIN_HANDLED)

add_executable(${PROJECT_NAME} src/main.cpp src/Screen.cpp src/Screen.h src/Rectangle.cpp src/Rectangle.h src/BubbleSort.cpp src/BubbleSort.h)
target_link_libraries(
        ${PROJECT_NAME} ${SDL2_LIB_DIR}/libSDL2.dll.a ${SDL2_LIB_DIR}/libSDL2main.a
        ${SDL2_LIB_DIR}/libSDL2_image.dll.a)