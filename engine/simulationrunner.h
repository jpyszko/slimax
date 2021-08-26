//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONRUNNER_H
#define SLIMAX_SIMULATIONRUNNER_H

#include <memory>
#include "../model/simulation.h"
#include "simulationbuilder.h"
#include "notificator.h"

using namespace std;

/*!
 * Typ wyliczeniowy oznaczający wynik symulacji.
 */
enum SimulationResult{
    SNAILS_WINS,
    PLANTS_WINS,
    DRAW
};

/*!
 * Klasa odpowiedzalna za wykonanie symulacji. Symulacja wykonywana jest turowo. Kazdd tura składa się z wylosowania
 * ślimaka i jego pokarmu oraz wylosowania rośliny do wzrostu. Na 1 sekundę składa się 5 tur.
 */
class SimulationRunner {

public:

    /*!
     * Konstruktor tworzący klasę
     * @param notificator - subskrybent który będzie otrzymywał informacje o zmianach od obecnej klasy
     */
    SimulationRunner(shared_ptr<Notificator> notificator);

    /*!
     * Metoda odpowiedzalna za załadowanie obiektu symulacji z obiektu SimulationBuilder.
     * Jeśli SimulationRunner posiadał już załadowaną symulację zostanie ona zastąpiona.
     * @param simulationBuilder - obiekt budowniczego z inicjalnymi danymi symluacji do załadowania
     */
    void load(SimulationBuilder& simulationBuilder);

    /*!
     * Metoda wykonująca symulację turowo. Symulacja kończy się jeśli zostanie wykorzystany całkowity czas przewidziany
     * na symulację, ślimaki i rośłiny zajmą całkowitą powierzchnie dna akwarium lub gdy jedna ze stron całkowicie zniknie.
     * @return wynik symluacji
     */
    SimulationResult run();

private:
    const int roundsPerSecond = 5;
    unique_ptr<Simulation> simulation;
    shared_ptr<Notificator> notificator;

    shared_ptr<Snail> getAliveRandom(RandomSet<shared_ptr<Snail>> &snails);

    shared_ptr<Plant> getAliveRandom(RandomSet<shared_ptr<Plant>> &plants);

    SimulationResult determineWinner(int numberOfSnails, int numberOfPlants);
};


#endif //SLIMAX_SIMULATIONRUNNER_H
