cmake_minimum_required(VERSION 3.26)
project(ApplicationCore)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} STATIC src/main.cpp src/application.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)