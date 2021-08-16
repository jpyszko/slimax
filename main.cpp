#include <iostream>
#include <QApplication>
#include "engine/SimulationBuilder.h"
#include "engine/SimulationRunner.h"
#include "console/ConsoleNotificator.h"
#include "gui/mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
//    SimulationBuilder builder;
//    SimulationBuilder &simulationBuilder = builder.simulation(10, 200, 500)
//            .addSnail("maciek", ROMAN_SNAIL, 5)
//            .addSnail("maciek2", ROMAN_SNAIL, 30)
//            .addSnail("maciek3", ROMAN_SNAIL, 20)
//            .addSnail("zenek", TURKISH_SNAIL, 10)
//            .addSnail("wojtek", GARDEN_SNAIL, 10)
//            .addPlant("salata", LETTUCE, 10)
//            .addPlant("trawa", GRASS, 30)
//            .addPlant("marchewka", CARROT, 12);
//    shared_ptr<Notificator> notificator = make_shared<ConsoleNotificator>();
//    SimulationRunner runner(notificator);
//    runner.load(simulationBuilder);
//    SimulationResult result = runner.run();
//
//    std::cout << result;
//
//    return 0;
}
