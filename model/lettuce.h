//
// Created by jpyszko on 18.07.2021.
//

#ifndef SLIMAX_LETTUCE_H
#define SLIMAX_LETTUCE_H

#include "plant.h"

/*!
 * Klasa opisująca zachowanie (sposób wzrostu) sałaty.
 */
class Lettuce : public Plant {

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji sałaty
     * @param initSize - początkowa powierzchnia zajmowana przez sałatę (rozmar)
     */
    Lettuce(string name, int initSize);

    /*!
     * Funkcja opisująca sposób (szybkość) rosnięcia sałąty. Szybkość przysrostu w przypadku sałąty jest zależna
     * od jej aktualnego rozmaru.
     */
    void grow() override;
};


#endif //SLIMAX_LETTUCE_H
