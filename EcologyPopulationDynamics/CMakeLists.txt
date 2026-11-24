cmake_minimum_required(VERSION 4.3)
project(EcologyPopulationDynamics)

set(CMAKE_CXX_STANDARD 11)

add_executable(EcologyPopulationDynamics main.cpp
        Species.cpp
        Species.h)
