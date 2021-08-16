//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONRUNNER_H
#define SLIMAX_SIMULATIONRUNNER_H

#include <memory>
#include "../model/Simulation.h"
#include "SimulationBuilder.h"
#include "Notificator.h"

using namespace std;

enum SimulationResult{
    SNAILS_WINS,
    PLANTS_WINS,
    DRAW
};

class SimulationRunner {

private:
    const int roundsPerSecond = 5;
    Simulation* simulation = nullptr;
    Notificator* notificator;

    shared_ptr<Snail> getAliveRandom(RandomSet<shared_ptr<Snail>> &snails);

    shared_ptr<Plant> getAliveRandom(RandomSet<shared_ptr<Plant>> &plants);

    SimulationResult determineWinner(int numberOfSnails, int numberOfPlants);

public:

    SimulationRunner(Notificator *notificator);

    void load(SimulationBuilder& simulationBuilder);

    SimulationResult run();
};


#endif //SLIMAX_SIMULATIONRUNNER_H
