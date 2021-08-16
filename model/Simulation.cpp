//
// Created by jpyszko on 01.08.2021.
//

#include "Simulation.h"

Simulation::Simulation(int duration, int aquariumWeight, int aquariumLength, RandomSet<shared_ptr<Snail>> snails,
                       RandomSet<shared_ptr<Plant>> plants)
        : duration(duration), aquariumArea(aquariumWeight * aquariumLength),
        snails(std::move(snails)), plants(std::move(plants)) {

}

RandomSet<shared_ptr<Snail>> Simulation::getSnails() {
    return snails;
}

RandomSet<shared_ptr<Plant>> Simulation::getPlants() {
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
