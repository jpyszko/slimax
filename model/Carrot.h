//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_CARROT_H
#define SLIMAX_CARROT_H


#include "Plant.h"

class Carrot : public Plant{

public:
    Carrot(string name, int initSize);

    void grow() override;
};


#endif //SLIMAX_CARROT_H
