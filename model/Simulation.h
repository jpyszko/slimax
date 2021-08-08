//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATION_H
#define SLIMAX_SIMULATION_H


#include "../template/RandomSet.h"
#include "Snail.h"
#include "Plant.h"

using namespace std;

class Simulation {

private:
    const int aquariumArea;
    const RandomSet<Snail*> snails;
    const RandomSet<Plant*> plants;

    int duration;

public:
    Simulation(int duration, int aquariumWeight, int aquariumLength,
               RandomSet<Snail *> snails, RandomSet<Plant *> plants);


    RandomSet<Snail*> getSnails();

    RandomSet<Plant*> getPlants();

    int getAquariumArea();

    int getDuration();

    void setDuration(int duration);

    ~Simulation() = default;
};


#endif //SLIMAX_SIMULATION_H
