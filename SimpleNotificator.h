//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_SIMPLENOTIFICATOR_H
#define SLIMAX_SIMPLENOTIFICATOR_H


#include <memory>
#include "engine/Notificator.h"
#include "template/RandomSet.h"
#include "model/Snail.h"
#include "model/Plant.h"

class SimpleNotificator : public Notificator{
public:
    void notify(int reminingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;
};


#endif //SLIMAX_SIMPLENOTIFICATOR_H
