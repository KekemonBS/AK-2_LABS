cmake_minimum_required(VERSION 3.10)

project(salculator)

include_directories(${PROJECT_SOURCE_DIR})

add_library(calc calculator.cpp)
add_executable(Lab2 calculator.cpp main.cpp)
