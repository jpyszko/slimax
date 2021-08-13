//
// Created by jpyszko on 31.07.2021.
//

#include "TurkishSnail.h"
#include <iostream>

TurkishSnail::TurkishSnail(string name, int initSize)
        : Snail(std::move(name), TURKISH_SNAIL, initSize) {

}

void TurkishSnail::eat(RandomSet<Plant *> plants) {
    Plant *plant = plants.getRandom();
    if (plant->getType() == GRASS) {
        int biteSize = getSize()/3;
        if (biteSize <=0){
            biteSize = 1;
        }
        int realBite = plant->bite(biteSize);
        setSize(getSize() + realBite);;
    } else {
        int decimal = getSize() / 2;
        int difference = decimal > 1 ? decimal : 1;
        setSize(getSize() - difference);
    }
}
