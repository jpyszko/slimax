//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_SNAIL_H
#define SLIMAX_SNAIL_H

#include <string>

using namespace std;

enum SnailType {
    TYPE_1,
    TYPE_2,
    TYPE_3
};

class Snail {

private:
    const string name;
    const SnailType type;
    int size;

protected:
    Snail(string name, SnailType type, int initSize);

public:
    string getName();

    SnailType getType();

    int getSize();

    bool operator< (const Snail &right) const
    {
        return name < right.name;
    }

};

#endif //SLIMAX_SNAIL_H
