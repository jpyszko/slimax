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
    SimulationBuilder &simulationBuilder = builder.simulation(10, 200, 500)
            .addSnail("maciek", ROMAN_SNAIL, 5)
            .addSnail("maciek2", ROMAN_SNAIL, 30)
            .addSnail("maciek3", ROMAN_SNAIL, 20)
            .addSnail("zenek", TURKISH_SNAIL, 10)
            .addSnail("wojtek", GARDEN_SNAIL, 10)
            .addPlant("salata", LETTUCE, 10)
            .addPlant("trawa", GRASS, 30)
            .addPlant("marchewka", CARROT, 12);
    SimpleNotificator notificator;
    SimulationRunner runner(&notificator);
    runner.load(simulationBuilder);
    SimulationResult result = runner.run();

    std::cout << result;

    return 0;
}
