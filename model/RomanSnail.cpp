//
// Created by jpyszko on 09.03.2021.
//

#include "RomanSnail.h"
#include <iostream>

RomanSnail::RomanSnail(string name, int initSize)
        : Snail(std::move(name), ROMAN_SNAIL, initSize) {

}

void RomanSnail::eat(RandomSet<Plant *> plants) {
    Plant *plant = plants.getRandom();
    if (plant->getType() == LETTUCE) {
        int biteSize = plant->bite(getSize() / 2 + 1);
        setSize(getSize() + biteSize);
    } else if (plant->getType() == CARROT) {
        int biteSize = plant->bite(getSize() / 4);
        setSize(getSize() + biteSize);
    } else {
        int decimal = getSize() / 3;
        int difference = decimal > 1 ? decimal : 1;
        setSize(getSize() - difference);
    }
}
