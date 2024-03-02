cmake_minimum_required(VERSION 3.26)
project(Animals)

set(CMAKE_CXX_STANDARD 17)

add_executable(Animals src/main.cpp
        src/Animal.cpp
        include/Animal.h
        src/Dog.cpp
        include/Dog.h)
