//
// Created by yaspe on 01.08.2021.
//

#include "GardenSnail.h"

#include <iostream>

GardenSnail::GardenSnail(string name, int initSize)
        : Snail(std::move(name), GARDEN_SNAIL, initSize) {

}

void GardenSnail::eat() {
    std::cout << "Garden eat"<< std::endl;
}
