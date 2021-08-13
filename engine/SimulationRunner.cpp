//
// Created by jpyszko on 01.08.2021.
//

#include <iostream>
#include "SimulationRunner.h"

SimulationRunner::SimulationRunner(Notificator *notificator) : notificator(notificator) {}

void SimulationRunner::load(SimulationBuilder& simulationBuilder) {
    simulation = simulationBuilder.build();
}

void SimulationRunner::run() {

    RandomSet<Snail *> snails = simulation->getSnails();
    RandomSet<Plant *> plants = simulation->getPlants();

    for(int i = 0; i<10; i++){
        Snail *snail = snails.getRandom();
        snail->eat(plants);

        Plant *plant = plants.getRandom();
        plant->grow();

        notificator->notify(1, snails, plants);
    }
}
