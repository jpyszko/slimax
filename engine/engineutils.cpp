//
// Created by jpyszko on 15.08.2021.
//

#include "engineutils.h"

int EngineUtils::countSnailsArea(RandomSet<shared_ptr<Snail>> &snails) {
    int totalSnailsArea = 0;
    for (const auto& elem : snails) {
        totalSnailsArea += elem->getSize();
    }
    return totalSnailsArea;
}

int EngineUtils::countPlantsArea(RandomSet<shared_ptr<Plant>> &plants) {
    int totalPlantsArea = 0;
    for (const auto& elem : plants) {
        totalPlantsArea += elem->getSize();
    }
    return totalPlantsArea;
}
