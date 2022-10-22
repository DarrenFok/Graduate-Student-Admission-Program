cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Project
        src/main.cpp
        src/stu_sort.cpp
        src/stu_sort.hpp
        src/student.cpp
        src/student.hpp
        src/toefl.cpp
        src/toefl.hpp src/functions.hpp)
