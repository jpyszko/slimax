//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_SNAIL_H
#define SLIMAX_SNAIL_H

#include <string>
#include "../template/RandomSet.h"
#include "Plant.h"

using namespace std;

enum SnailType {
    ROMAN_SNAIL,
    TURKISH_SNAIL,
    GARDEN_SNAIL
};

class Snail {

private:
    const string name;
    const SnailType type;
    int size;

protected:
    Snail(string name, SnailType type, int initSize);

    void setSize(int size);

public:
    virtual void eat(RandomSet<Plant *> plants) = 0;

    string getName();

    SnailType getType();

    int getSize();

    bool operator<(const Snail &right) const {
        return name < right.name;
    }

    ~Snail() = default;

};

#endif //SLIMAX_SNAIL_H
