//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATION_H
#define SLIMAX_SIMULATION_H

#include <memory>
#include "../template/RandomSet.h"
#include "Snail.h"
#include "Plant.h"

using namespace std;

class Simulation {

private:
    const int aquariumArea;
    const RandomSet<shared_ptr<Snail>> snails;
    const RandomSet<shared_ptr<Plant>> plants;

    int duration;

public:
    Simulation(int duration, int aquariumWeight, int aquariumLength,
               RandomSet<shared_ptr<Snail>> snails, RandomSet<shared_ptr<Plant>> plants);


    RandomSet<shared_ptr<Snail>> getSnails();

    RandomSet<shared_ptr<Plant>> getPlants();

    int getAquariumArea();

    int getDuration();

    void setDuration(int duration);

    ~Simulation() = default;
};


#endif //SLIMAX_SIMULATION_H
