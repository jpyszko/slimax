cmake_minimum_required(VERSION 3.17)
project(slimax)

set(CMAKE_CXX_STANDARD 14)

add_executable(slimax main.cpp model/Snail.cpp model/Snail.h model/SnailType1.cpp model/SnailType1.h model/Aquarium.cpp model/Aquarium.h template/RandomSet.h)