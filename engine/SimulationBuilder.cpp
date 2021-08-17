//
// Created by jpyszko on 01.08.2021.
//

#include "SimulationBuilder.h"

#include <memory>

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

unique_ptr<Simulation> SimulationBuilder::build() {
    validateAquariumSize(aquariumWeight, aquariumLength,snails,plants);
    return make_unique<Simulation>(duration, aquariumWeight, aquariumLength, snails, plants);
}

shared_ptr<Snail> SimulationBuilder::initSnail(string &name, SnailType type, int initSize) {
    switch(type){
        case ROMAN_SNAIL:
            return make_shared<RomanSnail>(name, initSize);
        case TURKISH_SNAIL:
            return make_shared<TurkishSnail>(name, initSize);
        case GARDEN_SNAIL:
            return make_shared<GardenSnail>(name, initSize);
    }

    throw ValidationException("Invalid snail type", INVALID_SNAIL_TYPE);
}

shared_ptr<Plant> SimulationBuilder::initPlant(string &name, PlantType type, int initSize) {
    switch (type) {
        case LETTUCE:
            return make_shared<Lettuce>(name, initSize);
        case GRASS:
            return make_shared<Grass>(name, initSize);
        case CARROT:
            return make_shared<Carrot>(name, initSize);

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

void SimulationBuilder::validateAquariumSize(int weight, int length, RandomSet<shared_ptr<Snail>> snails,
                                             RandomSet<shared_ptr<Plant>> plants) {
    int aquariumArea = weight * length;
    int totalSnailsArea = EngineUtils::countSnailsArea(snails);
    int totalPlantsArea = EngineUtils::countPlantsArea(plants);
    if(aquariumArea < totalSnailsArea + totalPlantsArea){
        throw ValidationException("Aquarium too small for declared snails and plants", AQUARIUM_TOO_SMALL);
    }

}

int SimulationBuilder::getAquariumWeight() {
    return aquariumWeight;
}

int SimulationBuilder::getAquariumLength() {
    return aquariumLength;
}
