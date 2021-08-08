//
// Created by jpyszko on 18.07.2021.
//

#ifndef SLIMAX_LETTUCE_H
#define SLIMAX_LETTUCE_H

#include "Plant.h"

class Lettuce : public Plant {

public:
    Lettuce(string name, int initSize);

    void grow() override;

    ~Lettuce() = default;
};


#endif //SLIMAX_LETTUCE_H
