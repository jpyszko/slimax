//
// Created by yaspe on 01.08.2021.
//

#ifndef SLIMAX_GARDENSNAIL_H
#define SLIMAX_GARDENSNAIL_H


#include "Snail.h"

using namespace std;

class GardenSnail : public Snail{

public:
    GardenSnail(string name, int initSize);

    void eat() override;

    ~GardenSnail() = default;
};


#endif //SLIMAX_GARDENSNAIL_H
