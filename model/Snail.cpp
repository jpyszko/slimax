//
// Created by jpyszko on 09.03.2021.
//

#include "Snail.h"

Snail::Snail(string name, SnailType type, int initSize)
        : name(name), type(type), size(initSize) {

}

string Snail::getName() {
    return name;
}

SnailType Snail::getType() {
    return type;
}

int Snail::getSize() {
    return size;
}


