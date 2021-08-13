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

SimulationBuilder& SimulationBuilder::simulation(int duration, int aquariumWeight, int aquariumLength) {
    this->duration = duration;
    this->aquariumWeight = aquariumLength;
    this->aquariumLength = aquariumWeight;
    return *this;
}

SimulationBuilder& SimulationBuilder::addSnail(string name, SnailType type, int initSize) {

    snails.add(initSnail(std::move(name), type,initSize));
    return *this;
}

SimulationBuilder& SimulationBuilder::addPlant(string name, PlantType type, int initSize) {
    plants.add(initPlant(std::move(name), type, initSize));
    return *this;
}

Simulation* SimulationBuilder::build() {
    return new Simulation{duration, aquariumWeight, aquariumLength, snails, plants};
}

Snail* SimulationBuilder::initSnail(string name, SnailType type, int initSize) {
    switch(type){
        case ROMAN_SNAIL:
            return new RomanSnail(name, initSize);
        case TURKISH_SNAIL:
            return new TurkishSnail(name, initSize);
        case GARDEN_SNAIL:
            return new GardenSnail(name, initSize);
    }

    throw "Wrong snail type";
}

Plant *SimulationBuilder::initPlant(string name, PlantType type, int initSize) {
    switch (type) {
        case LETTUCE:
            return new Lettuce(name, initSize);
        case GRASS:
            return new Grass(name, initSize);
        case CARROT:
            return new Carrot(name, initSize);

    }
    throw "Wrong plant type";
}
