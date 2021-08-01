//
// Created by jpyszko on 18.07.2021.
//

#include "Plant.h"


Plant::Plant(string name, PlantType type, int initSize)
            : name(name), type(type), size(initSize) {

}

string Plant::getName() {
    return name;
}

PlantType Plant::getType() {
    return type;
}

int Plant::getSize() {
    return size;
}
