cmake_minimum_required(VERSION 3.17)
project(slimax)

set(CMAKE_CXX_STANDARD 14)

add_executable(slimax main.cpp model/Snail.cpp model/Snail.h model/RomanSnail.cpp model/RomanSnail.h model/Aquarium.cpp model/Aquarium.h template/RandomSet.h model/Plant.cpp model/Plant.h model/Lettuce.cpp model/Lettuce.h model/TurkishSnail.cpp model/TurkishSnail.h model/GardenSnail.cpp model/GardenSnail.h model/Grass.cpp model/Grass.h model/Carrot.cpp model/Carrot.h)