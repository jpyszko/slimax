//
// Created by jpyszko on 09.03.2021.
//

#include "romansnail.h"

RomanSnail::RomanSnail(string name, int initSize)
        : Snail(std::move(name), ROMAN_SNAIL, initSize) {

}

void RomanSnail::eat(Plant &plant) {
    if (plant.getType() == LETTUCE) {
        int biteSize = plant.bite(getSize() / 2 + 1);
        setSize(getSize() + biteSize);
    } else if (plant.getType() == GRASS) {
        int biteSize = plant.bite(getSize() / 4);
        setSize(getSize() + biteSize);
    } else {
        int decimal = getSize() / 3;
        int difference = decimal > 1 ? decimal : 1;
        setSize(getSize() - difference);
    }
}
