//
// Created by jpyszko on 09.03.2021.
//

#include "snail.h"

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

void Snail::setSize(int size) {
    this->size = size;

}

string Snail::typeToString(SnailType snailType) {
    return typeNames.at(snailType);
}

SnailType Snail::stringToType(string snailTypeName) {
    for(const auto& elem : typeNames){
        if(elem.second == snailTypeName){
            return elem.first;
        }
    }

    return UNKNOWN_SNAIL;
}

const map<SnailType, string> Snail::typeNames = {{ROMAN_SNAIL,   "Winniczek"},
                                                 {TURKISH_SNAIL, "Turecki"},
                                                 {GARDEN_SNAIL,  "Ogrodowy"}};

