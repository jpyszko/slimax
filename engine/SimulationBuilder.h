//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONBUILDER_H
#define SLIMAX_SIMULATIONBUILDER_H


#include <memory>
#include "../template/RandomSet.h"
#include "../model/Snail.h"
#include "../model/Plant.h"
#include "../model/Simulation.h"

using namespace std;

class SimulationBuilder {

private:
    int aquariumWeight;
    int aquariumLength;
    RandomSet<shared_ptr<Snail>> snails;
    RandomSet<shared_ptr<Plant>> plants;

    int duration;

    void validateSimulation(int duration, int aquariumWeight, int aquariumLength);

    void validateSnail(string &name, int initSize);

    void validatePlant(string &name, int initSize);

    void validateAquariumSize(int weight, int length, RandomSet<shared_ptr<Snail>> snails,
                         RandomSet<shared_ptr<Plant>> plants);

    shared_ptr<Snail> initSnail(string &name, SnailType type, int initSize);

    shared_ptr<Plant> initPlant(string &name, PlantType type, int initSize);

public:
    SimulationBuilder& simulation(int duration, int aquariumWeight, int aquariumLength);

    SimulationBuilder& addSnail(string name, SnailType type, int initSize);

    SimulationBuilder& addPlant(string name, PlantType type, int initSize);

    unique_ptr<Simulation> build();

    int getAquariumWeight();

    int getAquariumLength();

    int getDuration();

    RandomSet<shared_ptr<Snail>> & getSnails();

    RandomSet<shared_ptr<Plant>> & getPlants();

};


#endif //SLIMAX_SIMULATIONBUILDER_H
