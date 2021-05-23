#include <iostream>
#include "model/Snail.h"
#include "model/SnailType1.h"
#include "template/RandomSet.h"

int main() {
    Snail snail = SnailType1("maciek", 5);
    RandomSet<Snail> snails;
    snails.add(snail);
    Snail random = snails.getRandom();

    std::cout << "Hello, World!" << random.getName() << std::endl;
    return 0;
}
