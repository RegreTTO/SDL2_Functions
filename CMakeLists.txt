cmake_minimum_required(VERSION 3.21)
project(sdl2)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sdl2 main.cpp itc_sdl_lib/itc_sdl1.cpp itc_sdl_lib/itc_sdl.h itc_sdl_lib/itc_sdl2.cpp itc_sdl_lib/itc_sdl1.h itc_sdl_lib/itc_sdl2.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})