//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_GARDENSNAIL_H
#define SLIMAX_GARDENSNAIL_H


#include "snail.h"

using namespace std;

/*!
 * Klasa opisująca zachowanie ślimaka ogrodowego.
 */
class GardenSnail : public Snail {

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji ślimaka
     * @param initSize - początkowa powierzchnia zajmowana przez ślimaka (rozmar)
     */
    GardenSnail(string name, int initSize);

    /*!
     * Funkcja opisująca nawyki żywieniowe ślimaka ogrodowego. Slimak bardziej lubi sałatę, spożywa też marchewkę.
     * Wielkość jego przyrostu jest  zależna od możliwego kęsu tych rośłin. Jeśli otrzyma inny pokarm chudnie.
     * @param plant - roślina, która została dostarczona ślimakowi do zjedzenia
     */
    void eat(Plant &plant) override;
};


#endif //SLIMAX_GARDENSNAIL_H
