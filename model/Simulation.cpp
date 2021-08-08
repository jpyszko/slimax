//
// Created by jpyszko on 01.08.2021.
//

#include "Simulation.h"

#include <utility>

Simulation::Simulation(int duration, int aquariumWeight, int aquariumLength, RandomSet<Snail *> snails,
                       RandomSet<Plant *> plants)
        : duration(duration), aquariumArea(aquariumWeight * aquariumLength),
        snails(std::move(snails)), plants(std::move(plants)) {

}

RandomSet<Snail *> Simulation::getSnails() {
    return snails;
}

RandomSet<Plant *> Simulation::getPlants() {
    return plants;
}

int Simulation::getAquariumArea() {
    return aquariumArea;
}

int Simulation::getDuration() {
    return duration;
}

void Simulation::setDuration(int duration) {
    this->duration = duration;
}
