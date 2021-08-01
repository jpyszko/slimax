//
// Created by jpyszko on 27.04.2021.
//

#ifndef SLIMAX_RANDOMSET_H
#define SLIMAX_RANDOMSET_H

#include <set>
#include <random>

template<typename T>
class RandomSet {

private:
    std::set<T> container;

    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution;

public:
    RandomSet() {
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        generator = std::default_random_engine(seed);
    }

    bool add(T element) {
        bool inserted = container.insert(element).second;
        distribution = std::uniform_int_distribution<>(0, container.size() - 1);

        return inserted;
    }

    T getRandom() {
        auto it = container.cbegin();
        int random = distribution(generator);
        std::advance(it, random);

        return *it;
    }

    auto begin(){
        return container.begin();
    }

    auto end(){
        return container.end();
    }

};

#endif //SLIMAX_RANDOMSET_H
