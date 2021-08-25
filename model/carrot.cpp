//
// Created by jpyszko on 01.08.2021.
//

#include "carrot.h"

Carrot::Carrot(string name, int initSize)
        : Plant(std::move(name), CARROT, initSize) {

}

void Carrot::grow() {
    int newSize = getSize() + getSize()/2;
    setSize(newSize);
}
