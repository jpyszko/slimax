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

int Plant::bite(int biteSize) {
    if(biteSize > getSize()){
        biteSize = getSize();
        setSize(0);
        return biteSize;
    }
    setSize(getSize() - biteSize);
    return biteSize;
}

void Plant::setSize(int size) {
    this->size = size;
}

string Plant::typeToString(PlantType plantType) {
    return typeNames.at(plantType);
}

PlantType Plant::stringToType(string plantTypeName) {
    for(const auto& elem : typeNames){
        if(elem.second == plantTypeName){
            return elem.first;
        }
    }

    return UNKNOWN_PLANT;
}

const map<PlantType, string> Plant::typeNames = {{LETTUCE,   "Sałata"},
                                                 {GRASS, "Trawa"},
                                                 {CARROT,  "Marchewka"}};
