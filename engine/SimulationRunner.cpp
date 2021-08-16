//
// Created by jpyszko on 01.08.2021.
//

#include <iostream>
#include <thread>
#include "SimulationRunner.h"
#include "EngineUtils.h"

SimulationRunner::SimulationRunner(Notificator *notificator) : notificator(notificator) {}

void SimulationRunner::load(SimulationBuilder &simulationBuilder) {
    simulation = simulationBuilder.build();
}

SimulationResult SimulationRunner::run() {

    RandomSet<shared_ptr<Snail>> snails = simulation->getSnails();
    RandomSet<shared_ptr<Plant>> plants = simulation->getPlants();

    int numberOfRounds = roundsPerSecond * simulation->getDuration();
    int timeBetweenRounds = 1000 / roundsPerSecond;

    for (int roundNumber = 0; roundNumber < numberOfRounds; roundNumber++) {
        shared_ptr<Snail> snail = getAliveRandom(snails);
        shared_ptr<Plant> food = getAliveRandom(plants);
        snail->eat(*food);

        shared_ptr<Plant> plant = getAliveRandom(plants);
        plant->grow();

        int totalSnailsArea = EngineUtils::countSnailsArea(snails);
        int totalPlantsArea = EngineUtils::countPlantsArea(plants);
        if (totalSnailsArea + totalPlantsArea > simulation->getAquariumArea()) {
            return determineWinner(totalSnailsArea, totalPlantsArea);
        }

        notificator->notify(1, snails, plants);

        std::this_thread::sleep_for(std::chrono::milliseconds(timeBetweenRounds));
    }

    int totalSnailsArea = EngineUtils::countSnailsArea(snails);
    int totalPlantsArea = EngineUtils::countPlantsArea(plants);
    return determineWinner(totalSnailsArea, totalPlantsArea);
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

shared_ptr<Snail> SimulationRunner::getAliveRandom(RandomSet<shared_ptr<Snail>> &snails) {
    shared_ptr<Snail> snail;
    do{
        snail = snails.getRandom();
    } while (snail->getSize() <= 0);

    return snail;
}

shared_ptr<Plant> SimulationRunner::getAliveRandom(RandomSet<shared_ptr<Plant>> &plants) {
    shared_ptr<Plant> plant;
    do{
        plant = plants.getRandom();
    } while (plant->getSize() <= 0);

    return plant;
}
