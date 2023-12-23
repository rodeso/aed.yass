cmake_minimum_required(VERSION 3.27)
project(AED1G135)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED1G135
        main.cpp
        include/Controller.h
        src/Controller.cpp
        include/Class.h
        src/Class.cpp
        include/Schedule.h
        src/Schedule.cpp
        include/Student.h
        src/Student.cpp
        include/UC.h
        src/UC.cpp)
