//
// Created by jpyszko on 01.08.2021.
//

#include "grass.h"

#include <utility>

Grass::Grass(string name, int intSize)
        : Plant(std::move(name), GRASS, intSize) {

}

void Grass::grow() {
    int newSize = getSize() * 2 + 5;
    setSize(newSize);
}
