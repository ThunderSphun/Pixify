cmake_minimum_required(VERSION 3.26)
project(PixifyEditor)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
add_executable(${PROJECT_NAME} src/main.cpp)
