cmake_minimum_required(VERSION 3.29)
project(todo_console)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json REQUIRED)

add_executable(
        todo_console
        main.cpp
        src/Tehtava.cpp
        include/TehtavaLista.h
        include/Tehtava.h
        src/TehtavaLista.cpp)

target_link_libraries(todo_console PRIVATE nlohmann_json::nlohmann_json)