//
// Created by jpyszko on 13.08.2021.
//

#include <iostream>
#include "consolenotificator.h"

void ConsoleNotificator::notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) {

    std::cout << "Rosliny: ";
    for (const auto& elem : plants) {
        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
    }
    std::cout << std::endl;

    std::cout << "Slimaki:";
    for (const auto& elem : snails) {
        std::cout << elem->getName() << ":" << elem->getSize() << " , ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}
