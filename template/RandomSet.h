//
// Created by jpyszko on 27.04.2021.
//

#ifndef SLIMAX_RANDOMSET_H
#define SLIMAX_RANDOMSET_H

#include <set>

template<typename T>
class RandomSet {

private:
    std::set<T> container;

public:
    RandomSet() = default;

    bool add(T element) {
        return container.insert(element).second;
    }

    T getRandom() {
        auto it = container.cbegin();
        int random = rand() % container.size();
        std::advance(it, random);

        return *it;
    }

};

#endif //SLIMAX_RANDOMSET_H
