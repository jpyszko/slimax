//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONBUILDER_H
#define SLIMAX_SIMULATIONBUILDER_H


#include <memory>
#include <QDataStream>
#include "../template/RandomSet.h"
#include "../model/Snail.h"
#include "../model/Plant.h"
#include "../model/Simulation.h"

using namespace std;

class SimulationBuilder {

private:
    int duration;
    int aquariumWeight;
    int aquariumLength;
    RandomSet<shared_ptr<Snail>> snails;
    RandomSet<shared_ptr<Plant>> plants;

    void validateSimulation(int duration, int aquariumWeight, int aquariumLength);

    void validateSnail(string &name, int initSize);

    void validatePlant(string &name, int initSize);

    void validateAquariumSize(int weight, int length, RandomSet<shared_ptr<Snail>> snails,
                         RandomSet<shared_ptr<Plant>> plants);

public:
    SimulationBuilder() = default;

    SimulationBuilder(int duration, int aquariumWeight, int aquariumLength, RandomSet<shared_ptr<Snail>> snails,
                      RandomSet<shared_ptr<Plant>> plants);

    SimulationBuilder& simulation(int duration, int aquariumWeight, int aquariumLength);

    SimulationBuilder& addSnail(string name, SnailType type, int initSize);

    SimulationBuilder& addPlant(string name, PlantType type, int initSize);

    unique_ptr<Simulation> build();

    int getAquariumWeight();

    int getAquariumLength();

    int getDuration();

    RandomSet<shared_ptr<Snail>> & getSnails();

    RandomSet<shared_ptr<Plant>> & getPlants();

    static shared_ptr<Snail> initSnail(basic_string<char> name, SnailType type, int initSize);

    static shared_ptr<Plant> initPlant(basic_string<char> name, PlantType type, int initSize);
};

QDataStream & operator<< (QDataStream& stream, SimulationBuilder& builder);
QDataStream & operator>> (QDataStream& stream, SimulationBuilder& builder);

QDataStream & operator<< (QDataStream& stream, RandomSet<shared_ptr<Snail>>& snails);
QDataStream & operator>> (QDataStream& stream, RandomSet<shared_ptr<Snail>>& snails);

QDataStream & operator<< (QDataStream& stream, RandomSet<shared_ptr<Plant>>& plants);
QDataStream & operator>> (QDataStream& stream, RandomSet<shared_ptr<Plant>>& plants);


#endif //SLIMAX_SIMULATIONBUILDER_H
