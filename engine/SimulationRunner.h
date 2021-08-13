//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONRUNNER_H
#define SLIMAX_SIMULATIONRUNNER_H

#include "../model/Simulation.h"
#include "SimulationBuilder.h"
#include "Notificator.h"

using namespace std;

class SimulationRunner {

private:

    Simulation* simulation = nullptr;

    Notificator* notificator;

public:

    SimulationRunner(Notificator *notificator);

    void load(SimulationBuilder& simulationBuilder);

    void run();

};


#endif //SLIMAX_SIMULATIONRUNNER_H
