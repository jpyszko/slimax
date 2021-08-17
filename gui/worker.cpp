//
// Created by jpyszko on 17.08.2021.
//

#include "worker.h"
#include "../engine/SimulationBuilder.h"
#include "../engine/Notificator.h"
#include "guinotificator.h"
#include "../engine/SimulationRunner.h"

Worker::Worker(Ui::MainWindow *mainWindow) : window(mainWindow) {}

void Worker::process() {
    SimulationBuilder builder;
    SimulationBuilder &simulationBuilder = builder.simulation(10, 200, 500)
            .addSnail("maciek", ROMAN_SNAIL, 5)
            .addSnail("maciek2", ROMAN_SNAIL, 30)
            .addSnail("maciek3", ROMAN_SNAIL, 20)
            .addSnail("zenek", TURKISH_SNAIL, 10)
            .addSnail("wojtek", GARDEN_SNAIL, 10)
            .addPlant("salata", LETTUCE, 10)
            .addPlant("trawa", GRASS, 30)
            .addPlant("marchewka", CARROT, 12);

    shared_ptr<Notificator> notificator = make_shared<GuiNotificator>(window);
    SimulationRunner runner(notificator);
    runner.load(simulationBuilder);
    window->aquariumValue->setText(QString::number(simulationBuilder.getAquariumLength() * simulationBuilder.getAquariumWeight()));
    SimulationResult result = runner.run();
    emit showResult(result);
    emit finished();
}
