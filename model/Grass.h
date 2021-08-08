//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_GRASS_H
#define SLIMAX_GRASS_H


#include "Plant.h"

class Grass : public Plant{

public:
    Grass(string name, int intSize);

    void grow() override;

    ~Grass() = default;
};


#endif //SLIMAX_GRASS_H
