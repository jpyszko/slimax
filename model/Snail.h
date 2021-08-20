//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_SNAIL_H
#define SLIMAX_SNAIL_H

#include <string>
#include <QObject>
#include "../template/RandomSet.h"
#include "Plant.h"

using namespace std;

enum SnailType {
    ROMAN_SNAIL,
    TURKISH_SNAIL,
    GARDEN_SNAIL,
    UNKNOWN
};

class Snail : public QObject {

private:
    const string name;
    const SnailType type;
    int size;

    const static map<SnailType, string> typeNames;

protected:
    Snail(string name, SnailType type, int initSize);

    void setSize(int size);

public:
    virtual void eat(Plant &plant) = 0;

    string getName();

    SnailType getType();

    int getSize();

    static string typeToString(SnailType);

    static SnailType stringToType(string snailTypeName);

    bool operator<(const Snail &right) const {
        return name < right.name;
    }

    virtual ~Snail() = default;

};

#endif //SLIMAX_SNAIL_H
