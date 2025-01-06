cmake_minimum_required(VERSION 3.29)
project(bug_fixing)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(bug_fixing
#        main1_res_1.cpp
#        main1_res_2_.cpp
        main1_res_2_fixed.cpp
)
