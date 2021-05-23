//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_SNAILTYPE1_H
#define SLIMAX_SNAILTYPE1_H

#include "Snail.h"

using namespace std;

class SnailType1 : public Snail {

public:
    SnailType1(string name, int initSize);

    void eat();

};


#endif //SLIMAX_SNAILTYPE1_H
