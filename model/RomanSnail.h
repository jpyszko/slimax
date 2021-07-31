//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_ROMANSNAIL_H
#define SLIMAX_ROMANSNAIL_H

#include "Snail.h"

using namespace std;

class RomanSnail : public Snail {

public:
    RomanSnail(string name, int initSize);

    void eat() override;

};


#endif //SLIMAX_ROMANSNAIL_H
