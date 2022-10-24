cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        main.cpp
        stu_sort.cpp
        stu_sort.hpp
        student.cpp
        student.hpp
        toefl.cpp
        toefl.hpp functions.hpp)
