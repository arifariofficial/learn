cmake_minimum_required(VERSION 3.29)
project(test2)

# Specify the path to Catch2 if it's installed via Homebrew
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/catch2/3.7.1/lib/cmake")

# Find Catch2 package
find_package(Catch2 REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add executable target
add_executable(test2 main.cpp)

# Link Catch2 to your executable
target_link_libraries(test2 Catch2::Catch2)
