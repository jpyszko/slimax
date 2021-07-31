//
// Created by yaspe on 18.07.2021.
//

#ifndef SLIMAX_PLANT_H
#define SLIMAX_PLANT_H

#include <string>

using namespace std;

enum PlantType {
    LETTUCE,
    P_TYPE_2,
    P_TYPE_3
};

class Plant {

private:
    const string name;
    const PlantType type;
    int size;

protected:
    Plant(string name, PlantType type, int initSize);

public:
    string getName();

    PlantType getType();

    int getSize();

    bool operator<(const Plant &right) const {
        return name < right.name;
    }

};


#endif //SLIMAX_PLANT_H
