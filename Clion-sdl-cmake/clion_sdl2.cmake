cmake_minimum_required(VERSION 3.1)
project(untitled6)
#include your sdl directory here mine was C:/MinGW 
#i installed it in the compiler directory 
set(SDL2_DIR C:/MinGW)
set(SDL2_LIB_DIR ${SDL2_DIR}/lib)

include_directories(${SDL2_DIR}/include)

add_definitions(-DSDL_MAIN_HANDLED)
add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/libSDL2.dll.a ${SDL2_LIB_DIR}/libSDL2main.a )
