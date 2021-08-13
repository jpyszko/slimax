#include <iostream>
#include <chrono>
#include "model/Snail.h"
#include "model/RomanSnail.h"
#include "template/RandomSet.h"
#include "model/Plant.h"
#include "model/Lettuce.h"
#include "model/TurkishSnail.h"
#include "model/GardenSnail.h"
#include "model/Grass.h"
#include "model/Carrot.h"
#include "engine/SimulationBuilder.h"
#include "engine/SimulationRunner.h"
#include "SimpleNotificator.h"

int main() {
    SimulationBuilder builder;
    SimulationBuilder &simulationBuilder = builder.simulation(1, 1, 1)
            .addSnail("maciek", ROMAN_SNAIL, 5)
            .addSnail("zenek", TURKISH_SNAIL, 10)
            .addSnail("wojtek", GARDEN_SNAIL, 10)
            .addPlant("salata", LETTUCE, 10)
            .addPlant("trawa", GRASS, 30)
            .addPlant("marchewka", CARROT, 12);
    SimpleNotificator notificator;
    SimulationRunner runner(&notificator);
    runner.load(simulationBuilder);
    runner.run();


//    RomanSnail romanSnail("maciek", 5);
//    TurkishSnail turkishSnail("zenek", 10);
//    GardenSnail gardenSnail("wojtek", 10);
//
//    RandomSet<Snail*> snails;
//    snails.add(&romanSnail);
//    snails.add(&turkishSnail);
//    snails.add(&gardenSnail);
//
//    Lettuce lettuce("salata", 10);
//    Grass grass("trawa", 30);
//    Carrot carrot("marchewka", 12);
//    RandomSet<Plant*> plants;
//    plants.add(&lettuce);
//    plants.add(&grass);
//    plants.add(&carrot);
//    for(int i = 0; i<10; i++){
//        Snail *snail = snails.getRandom();
//        std::cout << "Snail:" << snail->getName() << std::endl;
//        snail->eat(plants);
//        Plant *plant = plants.getRandom();
//        std::cout << "Plant:" << plant->getName() << std::endl;
//        plant->grow();
//    }
//    for (auto elem : plants)
//    {
//        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
//    }
//    std::cout << std::endl;
//    for (auto elem : snails)
//    {
//        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
//    }

    return 0;
}
