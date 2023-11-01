cmake_minimum_required(VERSION 3.26)
project(AED1G135)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED1G135
        Student.h
        UC.cpp
        Class.cpp
        Schedule.h
        Schedule.cpp
        Student.cpp
        Controller.cpp)
