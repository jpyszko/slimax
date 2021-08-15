//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONBUILDER_H
#define SLIMAX_SIMULATIONBUILDER_H


#include "../template/RandomSet.h"
#include "../model/Snail.h"
#include "../model/Plant.h"
#include "../model/Simulation.h"

using namespace std;

class SimulationBuilder {

private:
    int aquariumWeight;
    int aquariumLength;
    RandomSet<Snail*> snails;
    RandomSet<Plant*> plants;

    int duration;

    void validateSimulation(int duration, int aquariumWeight, int aquariumLength);

    void validateSnail(string &name, int initSize);

    void validatePlant(string &name, int initSize);

    void validateAquariumSize(int aquariumWeight, int aquariumLength, RandomSet<Snail*> snails, RandomSet<Plant*> plants);

    Snail* initSnail(string &name, SnailType type, int initSize);

    Plant* initPlant(string &name, PlantType type, int initSize);

public:
    SimulationBuilder& simulation(int duration, int aquariumWeight, int aquariumLength);

    SimulationBuilder& addSnail(string name, SnailType type, int initSize);

    SimulationBuilder& addPlant(string name, PlantType type, int initSize);

    Simulation* build();

    void validatePlant();
};


#endif //SLIMAX_SIMULATIONBUILDER_H
