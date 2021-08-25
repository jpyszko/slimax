//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_ROMANSNAIL_H
#define SLIMAX_ROMANSNAIL_H

#include "../template/randomset.h"
#include "snail.h"

using namespace std;
/*!
 * Klasa opisująca zachowanie ślimaka winniczka.
 */
class RomanSnail : public Snail {

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji ślimaka
     * @param initSize - początkowa powierzchnia zajmowana przez ślimaka (rozmar)
     */
    RomanSnail(string name, int initSize);

    /*!
     * Metoda opisaująca nazwyki żywieniowe ślimaka winniczka. Slimak żywi się sałatą i trawą. Wielkość przyrostu
     * zależy od wielkości kęsu rośliny. W przypadku podania innych roślin ślimak chudnie.
     * @param plant - roślina, która została dostarczona ślimakowi do zjedzenia
     */
    void eat(Plant &plant) override;
};


#endif //SLIMAX_ROMANSNAIL_H
