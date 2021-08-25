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

add_executable(slimax main.cpp model/snail.cpp model/snail.h model/romansnail.cpp model/romansnail.h template/randomset.h model/plant.cpp model/plant.h model/lettuce.cpp model/lettuce.h model/turkishsnail.cpp model/turkishsnail.h model/gardensnail.cpp model/gardensnail.h model/grass.cpp model/grass.h model/carrot.cpp model/carrot.h engine/SimulationRunner.cpp engine/SimulationRunner.h engine/SimulationBuilder.cpp engine/SimulationBuilder.h model/simulation.cpp model/simulation.h engine/Notificator.h console/ConsoleNotificator.cpp console/ConsoleNotificator.h engine/ValidationException.cpp engine/ValidationException.h engine/EngineUtils.cpp engine/EngineUtils.h gui/mainwindow.cpp gui/mainwindow.h gui/mainwindow.ui gui/editwindow.cpp gui/editwindow.h gui/editwindow.ui gui/guinotificator.cpp gui/guinotificator.h gui/worker.cpp gui/worker.h gui/tablecombobox.cpp gui/tablecombobox.h gui/snailscombobox.cpp gui/snailscombobox.h gui/plantscombobox.cpp gui/plantscombobox.h gui/tablespinbox.cpp gui/tablespinbox.h)

target_link_libraries(slimax
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )
