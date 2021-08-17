//
// Created by jpyszko on 17.08.2021.
//

#include <QMessageBox>
#include "worker.h"
#include "../engine/SimulationBuilder.h"
#include "../engine/Notificator.h"
#include "guinotificator.h"
#include "../engine/SimulationRunner.h"

Worker::Worker(QTableWidget *snailsTable, QTableWidget *plantsTable) : snailsTable(snailsTable), plantsTable(plantsTable) {
}

Worker::~Worker() { // Destructor
    // free resources
}

void Worker::process() { // Process. Start processing data.
    // allocate resources using new here
    SimulationBuilder builder;
    SimulationBuilder &simulationBuilder = builder.simulation(30, 200, 500)
            .addSnail("maciek", ROMAN_SNAIL, 5)
            .addSnail("maciek2", ROMAN_SNAIL, 30)
            .addSnail("maciek3", ROMAN_SNAIL, 20)
//            .addSnail("zenek", TURKISH_SNAIL, 10)
//            .addSnail("wojtek", GARDEN_SNAIL, 10)
            .addPlant("salata", LETTUCE, 10);
//            .addPlant("trawa", GRASS, 30)
//            .addPlant("marchewka", CARROT, 12);
    shared_ptr<Notificator> notificator = make_shared<GuiNotificator>(snailsTable, plantsTable);
    SimulationRunner runner(notificator);
    runner.load(simulationBuilder);
    SimulationResult result = runner.run();
    emit finished();
}
