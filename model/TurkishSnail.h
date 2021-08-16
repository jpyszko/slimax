//
// Created by jpyszko on 31.07.2021.
//

#ifndef SLIMAX_TURKISHSNAIL_H
#define SLIMAX_TURKISHSNAIL_H


#include "Snail.h"

using namespace std;

class TurkishSnail : public Snail {

public:
    TurkishSnail(string name, int initSize);

    void eat(Plant &plant) override;
};


#endif //SLIMAX_TURKISHSNAIL_H
