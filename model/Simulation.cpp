//
// Created by jpyszko on 01.08.2021.
//

#include "simulation.h"

Simulation::Simulation(int duration, int aquariumWeight, int aquariumLength, RandomSet<shared_ptr<Snail>> snails,
                       RandomSet<shared_ptr<Plant>> plants)
        : duration(duration), aquariumArea(aquariumWeight * aquariumLength),
        snails(std::move(snails)), plants(std::move(plants)) {

}

const RandomSet<shared_ptr<Snail>> &Simulation::getSnails() {
    return snails;
}

const RandomSet<shared_ptr<Plant>> &Simulation::getPlants() {
    return plants;
}

int Simulation::getAquariumArea() {
    return aquariumArea;
}

int Simulation::getDuration() {
    return duration;
}
