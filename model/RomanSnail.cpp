//
// Created by jpyszko on 09.03.2021.
//

#include "RomanSnail.h"
#include <iostream>

RomanSnail::RomanSnail(string name, int initSize)
        : Snail(std::move(name), ROMAN_SNAIL, initSize) {

}

void RomanSnail::eat() {
    std::cout << "Roman eat"<< std::endl;
}
