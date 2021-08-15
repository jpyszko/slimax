//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONRUNNER_H
#define SLIMAX_SIMULATIONRUNNER_H

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

    Snail* getAliveRandom(RandomSet<Snail *> &snails);

    Plant* getAliveRandom(RandomSet<Plant *> &plants);

    SimulationResult determineWinner(int numberOfSnails, int numberOfPlants);

public:

    SimulationRunner(Notificator *notificator);

    void load(SimulationBuilder& simulationBuilder);

    SimulationResult run();

};


#endif //SLIMAX_SIMULATIONRUNNER_H
