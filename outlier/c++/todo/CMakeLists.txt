cmake_minimum_required(VERSION 3.29)
project(c__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(c__
    main.cpp
        todo.h
        todo.cpp
        TodoManager.h
        TodoManager.cpp
        FileManager.cpp)
