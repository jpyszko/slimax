//
// Created by jpyszko on 18.07.2021.
//

#ifndef SLIMAX_PLANT_H
#define SLIMAX_PLANT_H

#include <string>
#include <map>

using namespace std;

enum PlantType {
    LETTUCE,
    GRASS,
    CARROT,
    UNKNOWN_PLANT
};

class Plant {

public:
    virtual void grow() = 0;

    int bite(int biteSize);

    string getName();

    PlantType getType();

    int getSize();

    static string typeToString(PlantType plantType);

    static PlantType stringToType(string plantTypeName);

    bool operator<(const Plant &right) const {
        return name < right.name;
    }

    virtual ~Plant() = default;

protected:
    Plant(string name, PlantType type, int initSize);

    void setSize(int size);

private:
    const string name;
    const PlantType type;
    int size;

    const static map<PlantType, string> typeNames;

};


#endif //SLIMAX_PLANT_H
