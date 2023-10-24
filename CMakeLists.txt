cmake_minimum_required(VERSION 3.26)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1
        Class.cpp
        Class.h
        main.cpp
        Student.cpp
        Student.h)
