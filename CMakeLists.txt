cmake_minimum_required(VERSION 3.20)
project(slimax)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(slimax main.cpp model/Snail.cpp model/Snail.h model/RomanSnail.cpp model/RomanSnail.h template/RandomSet.h model/Plant.cpp model/Plant.h model/Lettuce.cpp model/Lettuce.h model/TurkishSnail.cpp model/TurkishSnail.h model/GardenSnail.cpp model/GardenSnail.h model/Grass.cpp model/Grass.h model/Carrot.cpp model/Carrot.h engine/SimulationRunner.cpp engine/SimulationRunner.h engine/SimulationBuilder.cpp engine/SimulationBuilder.h model/Simulation.cpp model/Simulation.h engine/Notificator.h console/ConsoleNotificator.cpp console/ConsoleNotificator.h engine/ValidationException.cpp engine/ValidationException.h engine/EngineUtils.cpp engine/EngineUtils.h)

target_link_libraries(slimax
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )