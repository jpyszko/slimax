//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_GRASS_H
#define SLIMAX_GRASS_H


#include "plant.h"

/*!
 * Klasa opisująca zachowanie (sposób wzrostu) trawy.
 */
class Grass : public Plant{

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji trawy
     * @param initSize - początkowa powierzchnia zajmowana przez trawę (rozmar)
     */
    Grass(string name, int intSize);

    /*!
     * Funkcja opisująca sposób (szybkość) rosnięcia trawy. Szybkość przysrostu w przypadku trawy jest zależna
     * od jej aktualnego rozmaru.
     */
    void grow() override;
};


#endif //SLIMAX_GRASS_H
