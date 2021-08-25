//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_CARROT_H
#define SLIMAX_CARROT_H


#include "plant.h"

/*!
 * Klasa opisująca zachowanie (sposób wzrostu) marchewki.
 */
class Carrot : public Plant{

public:
    /*!
     * Konstruktor tworzący klasę
     * @param name - nazwa własna nadana danej instancji marchewki
     * @param initSize - początkowa powierzchnia zajmowana przez marchewkę (rozmar)
     */
    Carrot(string name, int initSize);

    /*!
     * Funkcja opisująca sposób (szybkość) rosnięcia trawy. Szybkość przysrostu w przypadku trawy jest zależna
     * od jej aktualnego rozmaru.
     * */
    void grow() override;
};


#endif //SLIMAX_CARROT_H
