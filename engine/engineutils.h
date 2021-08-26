//
// Created by jpyszko on 15.08.2021.
//

#ifndef SLIMAX_ENGINEUTILS_H
#define SLIMAX_ENGINEUTILS_H


#include <memory>
#include "../model/snail.h"
#include "../model/plant.h"
#include "../template/randomset.h"

/*!
 * Klasa narzędziowa modulu engine zawierjąca statyczne metody
 */
class EngineUtils {

public:
    /*!
     * Metoda obliczająca aktualne pole powierzchni zajmowane przez wszystkie ślimaki.
     * @param snails - zbiór ślimaków uwzględniany w obliczeniu
     * @return wartość pola powierzchni
     */
    static int countSnailsArea(RandomSet<shared_ptr<Snail>> &snails);

    /*!
     * Metoda obliczająca aktualne pole powierzchni zajmowane przez wszystkie rośliny.
     * @param plants - zbiór roślin uwzględniany w obliczeniu
     * @return wartość pola powierzchni
     */
    static int countPlantsArea(RandomSet<shared_ptr<Plant>> &plants);
};


#endif //SLIMAX_ENGINEUTILS_H
