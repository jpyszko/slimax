//
// Created by jpyszko on 13.08.2021.
//

#ifndef SLIMAX_CONSOLENOTIFICATOR_H
#define SLIMAX_CONSOLENOTIFICATOR_H


#include <memory>
#include "../engine/notificator.h"
#include "../template/randomset.h"
#include "../model/snail.h"
#include "../model/plant.h"

/*!
 * Klasa subskrybenta dla konsoli reagująca na zmiany w modelu danych symulacji. Uzywana jedynie podczas developmentu.
 */
class ConsoleNotificator : public Notificator{

public:
    /*!
     * Metoda uruchamiana przez silnik symulacji w celu powiadomienia o dokonanych zmianach w modelu.
     * Odpowiedzialna za wypisywanie prostych komunikatów tekstowy odnośnie aktulanego stanu symulacji.
     * @param remainingTime - aktualny pozostały czas w sekundach
     * @param snails - aktualny zbiór slimaków
     * @param plants - aktualny zbiór roślin
     */
    void notify(int reminingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;
};


#endif //SLIMAX_CONSOLENOTIFICATOR_H
