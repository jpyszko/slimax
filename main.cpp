#include <iostream>
#include "model/Snail.h"
#include "model/RomanSnail.h"
#include "template/RandomSet.h"
#include "model/Plant.h"
#include "model/Lettuce.h"
#include "model/TurkishSnail.h"
#include "model/GardenSnail.h"

int main() {
    RomanSnail romanSnail = RomanSnail("maciek", 5);
    TurkishSnail turkishSnail = TurkishSnail("zenek", 10);
    GardenSnail gardenSnail = GardenSnail("wojtek", 10);
    RandomSet<Snail*> snails;
    snails.add(&romanSnail);
    snails.add(&turkishSnail);
    snails.add(&gardenSnail);
    Snail *random = snails.getRandom();
    random->eat();

    Plant lettuce = Lettuce("salata", 10);
    RandomSet<Plant> plants;
    plants.add(lettuce);
    Plant randomPlant = plants.getRandom();

    std::cout << "Snail:" << random->getName() << std::endl;
    std::cout << "Plant:" << randomPlant.getName() << std::endl;
    return 0;
}
