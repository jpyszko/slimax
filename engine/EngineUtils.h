//
// Created by jpyszko on 15.08.2021.
//

#ifndef SLIMAX_ENGINEUTILS_H
#define SLIMAX_ENGINEUTILS_H


#include "../model/Snail.h"
#include "../model/Plant.h"

class EngineUtils {

public:
    static int countSnailsArea(RandomSet<Snail *> &snails);

    static int countPlantsArea(RandomSet<Plant *> &plants);

};


#endif //SLIMAX_ENGINEUTILS_H
