//
// Created by jpyszko on 31.07.2021.
//

#ifndef SLIMAX_TURKISHSNAIL_H
#define SLIMAX_TURKISHSNAIL_H


#include "snail.h"

using namespace std;
/*!
 * Klasa opisująca zachowanie ślimaka tureckiego.
 */
class TurkishSnail : public Snail {

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji ślimaka
     * @param initSize - początkowa powierzchnia zajmowana przez ślimaka (rozmar)
     */
    TurkishSnail(string name, int initSize);

    /*!
     * Funkcja opisująca nawyki żywieniowe ślimaka tureckiego. Slimak spożywa tylko trawę. Wielkość jego przyrostu jest
     * zależna od możliwego kęsu. Jeśli otrzyma inny pokarm chudnie.
     * @param plant - roślina, która została dostarczona ślimakowi do zjedzenia
     */
    void eat(Plant &plant) override;
};


#endif //SLIMAX_TURKISHSNAIL_H
