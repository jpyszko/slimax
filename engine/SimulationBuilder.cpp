//
// Created by jpyszko on 01.08.2021.
//

#include "SimulationBuilder.h"

#include "../model/RomanSnail.h"
#include "../model/TurkishSnail.h"
#include "../model/GardenSnail.h"
#include "../model/Lettuce.h"
#include "../model/Grass.h"
#include "../model/Carrot.h"
#include "ValidationException.h"
#include "EngineUtils.h"

SimulationBuilder& SimulationBuilder::simulation(int duration, int aquariumWeight, int aquariumLength) {

    validateSimulation(duration, aquariumWeight, aquariumLength);
    this->duration = duration;
    this->aquariumWeight = aquariumLength;
    this->aquariumLength = aquariumWeight;
    return *this;
}

SimulationBuilder& SimulationBuilder::addSnail(string name, SnailType type, int initSize) {

    validateSnail(name, initSize);
    snails.add(initSnail(name, type,initSize));
    return *this;
}

SimulationBuilder& SimulationBuilder::addPlant(string name, PlantType type, int initSize) {

    validatePlant(name, initSize);
    plants.add(initPlant(name, type, initSize));
    return *this;
}

Simulation* SimulationBuilder::build() {
    validateAquariumSize(aquariumWeight, aquariumLength,snails,plants);
    return new Simulation{duration, aquariumWeight, aquariumLength, snails, plants};
}

Snail* SimulationBuilder::initSnail(string &name, SnailType type, int initSize) {
    switch(type){
        case ROMAN_SNAIL:
            return new RomanSnail(name, initSize);
        case TURKISH_SNAIL:
            return new TurkishSnail(name, initSize);
        case GARDEN_SNAIL:
            return new GardenSnail(name, initSize);
    }

    throw ValidationException("Invalid snail type", INVALID_SNAIL_TYPE);
}

Plant *SimulationBuilder::initPlant(string &name, PlantType type, int initSize) {
    switch (type) {
        case LETTUCE:
            return new Lettuce(name, initSize);
        case GRASS:
            return new Grass(name, initSize);
        case CARROT:
            return new Carrot(name, initSize);

    }
    throw ValidationException("Invalid plant type", INVALID_PLANT_TYPE);
}

void SimulationBuilder::validateSnail(string &name, int initSize) {
    if (name.empty()){
        throw ValidationException("Empty snail name", EMPTY_SNAIL_NAME);
    }
    if (initSize <= 0){
        throw ValidationException("Initial snail size have to be grater than 0", INVALID_SNAIL_SIZE);
    }
}

void SimulationBuilder::validatePlant(string &name, int initSize) {
    if (name.empty()){
        throw ValidationException("Empty plant name", EMPTY_PLANT_SIZE);
    }
    if (initSize <= 0){
        throw ValidationException("Initial plant size have to be grater than 0", INVALID_PLANT_SIZE);
    }
}

void SimulationBuilder::validateSimulation(int duration, int aquariumWeight, int aquariumLength) {
    if(duration <= 0){
        throw ValidationException("Simulation duration have to be grater than 0", INVALID_DURATION);
    }
    if(aquariumWeight <= 0 && aquariumLength <=0){
        throw ValidationException("Aquarium dimensions have to be grater than 0", INVALID_AQUARIUM_SIZE);
    }
}

void SimulationBuilder::validateAquariumSize(int aquariumWeight, int aquariumLength,
                                             RandomSet<Snail *> snails, RandomSet<Plant *> plants) {
    int aquariumArea = aquariumWeight * aquariumLength;
    int totalSnailsArea = EngineUtils::countSnailsArea(snails);
    int totalPlantsArea = EngineUtils::countPlantsArea(plants);
    if(aquariumArea < totalSnailsArea + totalPlantsArea){
        throw ValidationException("Aquarium too small for declared snails and plants", AQUARIUM_TOO_SMALL);
    }

}
