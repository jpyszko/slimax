//
// Created by jpyszko on 01.08.2021.
//

#include "GardenSnail.h"

#include <iostream>

GardenSnail::GardenSnail(string name, int initSize)
        : Snail(std::move(name), GARDEN_SNAIL, initSize) {

}

void GardenSnail::eat(Plant &plant) {
    if (plant.getType() == LETTUCE) {
        int biteSize = getSize() / 2;
        if (biteSize <= 0) {
            biteSize = 2;
        }
        int realBite = plant.bite(biteSize);
        setSize(getSize() + realBite);
    } else if (plant.getType() == CARROT) {
        int biteSize = getSize() / 4;
        if (biteSize <= 0) {
            biteSize = 1;
        }
        int realBite = plant.bite(biteSize);
        setSize(getSize() + realBite);
    } else {
        int decimal = getSize() / 3;
        int difference = decimal > 1 ? decimal : 1;
        setSize(getSize() - difference);
    }
}
