//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATION_H
#define SLIMAX_SIMULATION_H

#include <memory>
#include "../template/randomset.h"
#include "snail.h"
#include "plant.h"

using namespace std;

/*!
 * Kontener zawierający wszystkie wartości i obiekty potrzebne podczas symulacji. Do takich należ zaliczyć czas wykonywania symulacji,
 * pole powierzchni akwarium na którym dokonywana jest symulacja, zbiór ślimaków oraz roślin biorących udział w symulacji.
 */
class Simulation {

public:
    /*!
     * Konstruktor tworzący obiekt symulacji.
     * @param duration - czas symulacji
     * @param aquariumWeight - szerokość akwarium, w którym dokonywana jest symulacja
     * @param aquariumLength - dlugość akwarium, w któym dokonywana jest symulacja
     * @param snails - zbiór ślimaków biorących udziałw symulacji
     * @param plants - zbiór roślin biorących udział w symulacji
     */
    Simulation(int duration, int aquariumWeight, int aquariumLength,
               RandomSet<shared_ptr<Snail>> snails, RandomSet<shared_ptr<Plant>> plants);

    /*!
     * Metoda dostępowa dla zbioru ślimaków biorących udział w symluacji
     * @return aktulany zbiór ślimaków dla symulacji
     */
    const RandomSet<shared_ptr<Snail>> &getSnails();

    /*!
     * * Metoda dostępowa dla zbioru roślin biorących udział w symluacji
     * * @return aktulany zbiór roślin dla symulacji
     * */
    const RandomSet<shared_ptr<Plant>> &getPlants();

    /*!
     * Metoda dosepowa dla pole powierzchni akwarium na którym rozgrywa sięsymulacja.
     * @return pole powierzchni dna akwarium
     */
    int getAquariumArea();

    /*!
     * Metoda dosepowa dla maksymalnego czasu symulacji.
     * @return czas symulacji
     */
    int getDuration();

private:
    const int duration;
    const int aquariumArea;
    const RandomSet<shared_ptr<Snail>> snails;
    const RandomSet<shared_ptr<Plant>> plants;

};

#endif //SLIMAX_SIMULATION_H
