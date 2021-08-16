//
// Created by jpyszko on 18.07.2021.
//

#ifndef SLIMAX_PLANT_H
#define SLIMAX_PLANT_H

#include <string>

using namespace std;

enum PlantType {
    LETTUCE,
    GRASS,
    CARROT
};

class Plant {

private:
    const string name;
    const PlantType type;
    int size;

protected:
    Plant(string name, PlantType type, int initSize);

    void setSize(int size);

public:
    virtual void grow() = 0;

    int bite(int biteSize);

    string getName();

    PlantType getType();

    int getSize();

    bool operator<(const Plant &right) const {
        return name < right.name;
    }

    virtual ~Plant() = default;

};


#endif //SLIMAX_PLANT_H
