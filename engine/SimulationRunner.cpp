//
// Created by jpyszko on 01.08.2021.
//

#include <iostream>
#include <thread>
#include "SimulationRunner.h"

SimulationRunner::SimulationRunner(Notificator *notificator) : notificator(notificator) {}

void SimulationRunner::load(SimulationBuilder &simulationBuilder) {
    simulation = simulationBuilder.build();
}

SimulationResult SimulationRunner::run() {

    RandomSet<Snail *> snails = simulation->getSnails();
    RandomSet<Plant *> plants = simulation->getPlants();

    int numberOfRounds = roundsPerSecond * simulation->getDuration();
    int timeBetweenRounds = 1000 / roundsPerSecond;

    for (int roundNumber = 0; roundNumber < numberOfRounds; roundNumber++) {
        Snail *snail = getAliveRandom(snails);
        Plant *food = getAliveRandom(plants);
        snail->eat(*food);

        Plant *plant = getAliveRandom(plants);
        plant->grow();

        int totalSnailsArea = countSnailsArea(snails);
        int totalPlantsArea = countPlantsArea(plants);
        if (totalSnailsArea + totalPlantsArea > simulation->getAquariumArea()) {
            return determineWinner(totalSnailsArea, totalPlantsArea);
        }

        notificator->notify(1, snails, plants);

        std::this_thread::sleep_for(std::chrono::milliseconds(timeBetweenRounds));
    }

    int totalSnailsArea = countSnailsArea(snails);
    int totalPlantsArea = countPlantsArea(plants);
    return determineWinner(totalSnailsArea, totalPlantsArea);
}

int SimulationRunner::countSnailsArea(RandomSet<Snail *> &snails) {
    int totalSnailsArea = 0;
    for (auto elem : snails) {
        totalSnailsArea += elem->getSize();
    }
    return totalSnailsArea;
}

int SimulationRunner::countPlantsArea(RandomSet<Plant *> &plants) {
    int totalPlantsArea = 0;
    for (auto elem : plants) {
        totalPlantsArea += elem->getSize();
    }
    return totalPlantsArea;
}

SimulationResult SimulationRunner::determineWinner(int numberOfSnails, int numberOfPlants) {
    if (numberOfSnails > numberOfPlants) {
        return SNAILS_WINS;
    } else if (numberOfSnails < numberOfPlants) {
        return PLANTS_WINS;
    } else {
        return DRAW;
    }
}

Snail *SimulationRunner::getAliveRandom(RandomSet<Snail *> &snails) {
    Snail *snail;
    do{
        snail = snails.getRandom();
    } while (snail->getSize() <= 0);

    return snail;
}

Plant *SimulationRunner::getAliveRandom(RandomSet<Plant *> &plants) {
    Plant *plant;
    do{
        plant = plants.getRandom();
    } while (plant->getSize() <= 0);

    return plant;
}
