//
// Created by jpyszko on 31.07.2021.
//

#include "TurkishSnail.h"
#include <iostream>

TurkishSnail::TurkishSnail(string name, int initSize)
        : Snail(std::move(name), TURKISH_SNAIL, initSize) {

}

void TurkishSnail::eat() {
    std::cout << "Turkish eat"<< std::endl;

}
