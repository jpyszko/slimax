//
// Created by jpyszko on 18.07.2021.
//

#include "lettuce.h"

Lettuce::Lettuce(string name, int initSize) :
        Plant(name, LETTUCE, initSize) {
}

void Lettuce::grow() {
    int newSize = getSize() * 3;
    setSize(newSize);
}
