//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_SIMPLENOTIFICATOR_H
#define SLIMAX_SIMPLENOTIFICATOR_H


#include "engine/Notificator.h"
#include "template/RandomSet.h"
#include "model/Snail.h"
#include "model/Plant.h"

class SimpleNotificator : public Notificator{
public:
    void notify(int reminingTime, RandomSet<Snail *> &snails, RandomSet<Plant *> &plants) override;
};


#endif //SLIMAX_SIMPLENOTIFICATOR_H
