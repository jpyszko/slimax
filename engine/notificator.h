//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_NOTIFICATOR_H
#define SLIMAX_NOTIFICATOR_H

#include <memory>
#include "../template/randomset.h"
#include "../model/snail.h"
#include "../model/plant.h"

/*!
 * Interfejs subskrybenta uruchamiany przez silnik w celu poinformawania o zmianach. Klasa potomna powinna
 * przeciązać metodę notify w której uzyskuje dostęp do aktualnych danych w trakcie wykonywania symulacji.
 */
class Notificator {

public:

    /*!
     * Metoda abstrakcyjna wywoływana przez ślinik w trakcie wykonywania symluacji. Dostarcza aktualnych
     * danych pośrednich symulacji.
     * @param remainingTime - pozostały czas symulacji
     * @param snails - aktualny zbioru ślimaków
     * @param plants - aktualny zbiór rośłin
     */
    virtual void notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) = 0;
};

#endif //SLIMAX_NOTIFICATOR_H
