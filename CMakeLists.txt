cmake_minimum_required(VERSION 3.27)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(
        Calculator main.cpp
        src/calculator.cpp
        src/calculator.h)
