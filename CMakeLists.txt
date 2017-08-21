cmake_minimum_required(VERSION 2.8)
project(Cider_Fire)


set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Screen.cpp Screen.h)
add_executable(Cider_Fire ${SOURCE_FILES})

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp)

target_link_libraries(Cider_Fire ${SDL2_LIBRARY})




