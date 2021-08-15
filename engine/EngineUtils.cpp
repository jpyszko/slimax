//
// Created by jpyszko on 15.08.2021.
//

#include "EngineUtils.h"

int EngineUtils::countSnailsArea(RandomSet<Snail *> &snails) {
    int totalSnailsArea = 0;
    for (auto elem : snails) {
        totalSnailsArea += elem->getSize();
    }
    return totalSnailsArea;
}

int EngineUtils::countPlantsArea(RandomSet<Plant *> &plants) {
    int totalPlantsArea = 0;
    for (auto elem : plants) {
        totalPlantsArea += elem->getSize();
    }
    return totalPlantsArea;
}
