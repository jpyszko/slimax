cmake_minimum_required(VERSION 3.17)
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

add_executable(slimax main.cpp model/Snail.cpp model/Snail.h model/RomanSnail.cpp model/RomanSnail.h template/randomset.h model/Plant.cpp model/Plant.h model/Lettuce.cpp model/Lettuce.h model/turkishsnail.cpp model/turkishsnail.h model/GardenSnail.cpp model/GardenSnail.h model/Grass.cpp model/Grass.h model/Carrot.cpp model/Carrot.h engine/SimulationRunner.cpp engine/SimulationRunner.h engine/SimulationBuilder.cpp engine/SimulationBuilder.h model/Simulation.cpp model/Simulation.h engine/Notificator.h console/ConsoleNotificator.cpp console/ConsoleNotificator.h engine/ValidationException.cpp engine/ValidationException.h engine/EngineUtils.cpp engine/EngineUtils.h gui/mainwindow.cpp gui/mainwindow.h gui/mainwindow.ui gui/editwindow.cpp gui/editwindow.h gui/editwindow.ui gui/guinotificator.cpp gui/guinotificator.h gui/worker.cpp gui/worker.h gui/tablecombobox.cpp gui/tablecombobox.h gui/snailscombobox.cpp gui/snailscombobox.h gui/plantscombobox.cpp gui/plantscombobox.h gui/tablespinbox.cpp gui/tablespinbox.h)

target_link_libraries(slimax
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )
