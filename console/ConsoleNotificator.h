//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_CONSOLENOTIFICATOR_H
#define SLIMAX_CONSOLENOTIFICATOR_H


#include <memory>
#include "../engine/Notificator.h"
#include "../template/RandomSet.h"
#include "../model/Snail.h"
#include "../model/Plant.h"

class ConsoleNotificator : public Notificator{
public:
    void notify(int reminingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;
};


#endif //SLIMAX_CONSOLENOTIFICATOR_H
