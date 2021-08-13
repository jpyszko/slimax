//
// Created by jpyszko on 13.08.2021.
//

#include <iostream>
#include "SimpleNotificator.h"

void SimpleNotificator::notify(int remainingTime, RandomSet<Snail *> &snails, RandomSet<Plant *> &plants) {

    std::cout << "Rosliny: ";
    for (auto elem : plants) {
        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
    }
    std::cout << std::endl;

    std::cout << "Slimaki:";
    for (auto elem : snails) {
        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}
