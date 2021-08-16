//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_NOTIFICATOR_H
#define SLIMAX_NOTIFICATOR_H

#include <memory>
#include "../template/RandomSet.h"
#include "../model/Snail.h"
#include "../model/Plant.h"

class Notificator {

public:

    virtual void notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) = 0;
};

#endif //SLIMAX_NOTIFICATOR_H
