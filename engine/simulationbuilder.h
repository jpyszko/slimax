//
// Created by jpyszko on 01.08.2021.
//

#ifndef SLIMAX_SIMULATIONBUILDER_H
#define SLIMAX_SIMULATIONBUILDER_H


#include <memory>
#include <QDataStream>
#include "../template/randomset.h"
#include "../model/snail.h"
#include "../model/plant.h"
#include "../model/simulation.h"

using namespace std;

/*!
 * Klasa budowniczego przechowującego inicjalne dane symulacji. Umozlwia proste dodawanie klas ślimaków i roślin
 * do modelu wyłącznie na podstawie ich argumentów. Buduje obiekt Simulation wykorzystywany do właściwej symulacji.
 */
class SimulationBuilder {

public:

    /*!
     * Konstruktor bezparametrowy tworzący obiekt z pustym modelem.
     */
    SimulationBuilder() = default;

    /*!
     * Konstruktor tworzący obiekt z predefinowanami wartościami wszystkich pól.
     * @param duration - dlugość symulacji w sekundach
     * @param aquariumWeight - szerokość akwarium
     * @param aquariumLength - długość akwarium
     * @param snails - zbiur śłimaków biorących udział w symulacji
     * @param plants - zbiór roślin biorących udziałw symulacji
     */
    SimulationBuilder(int duration, int aquariumWeight, int aquariumLength, RandomSet<shared_ptr<Snail>> snails,
                      RandomSet<shared_ptr<Plant>> plants);

    /*!
     * Metoda ładująca podstawowe dane symulacji do modelu. Ponaddto metoda sprawdza poprawność wprowadzonych danych.
     * @param duration - długość symulacji w sekundach
     * @param aquariumWeight - szerokość akwarium
     * @param aquariumLength - długośćakwarium
     * @return obecny obiekt buildera
     */
    SimulationBuilder& simulation(int duration, int aquariumWeight, int aquariumLength);

    /*!
     * Metoda dodająca odpowiednią klasę ślimaka do symulacji. Klasa wybierana jest na podstawie wartości typu.
     * Ponaddto metoda sprawdza poprawność wprowadzonych danych.
     * @param name - nazwa własna ślimaka
     * @param type - typ ślimaka
     * @param initSize - początkowe pole powierzchni zajmowane przez ślimaka
     * @return obiecny obiekt buildera
     */
    SimulationBuilder& addSnail(string name, SnailType type, int initSize);

    /*!
     * Metoda dodająca odpowiednią klasę rośliny do symulacji. Klasa wybierana jest na podstawie wartości typu.
     * Ponaddto metoda sprawdza poprawność wprowadzonych danych.
     * @param name - nazwa własna rośliny
     * @param type - typ rośliny
     * @param initSize - początkowe pole powierzchni zajmowane przez roślinę
     * @return obecny obiekt buildera
     */
    SimulationBuilder& addPlant(string name, PlantType type, int initSize);

    /*!
     * Metoda kopiująca dane do obiektu symulacji. Ponaddto metoda sprawdza poprawność wprowadzonych danych
     * m. in. wielkość powierzchni akwarium do powierzchni ślimaków i rośłin.
     * @return obiekt symulacji
     */
    unique_ptr<Simulation> build();


    /*!
     * Metoda dostępowa dla aktualnie wprowadzonej szerokości akwarium.
     * @return szerokość akwairum
     */
    int getAquariumWeight();

    /*!
     * Metoda dostępowa dla aktualnie wprowadzonej długości akwairum.
     * @return długość akwiarium
     */
    int getAquariumLength();

    /*!
     * Metoda dostępowa dla czasu trwania symulacji
     * @return czas trwania symulacji w sekundach
     */
    int getDuration();

    /*!
     * Metoda dostępowa do wporowadzonego zbioru ślimaków
     * @return zbiór ślimaków
     */
    RandomSet<shared_ptr<Snail>> & getSnails();

    /*!
     * Metoda dostępowa do wporwadzonego zbior roślin
     * @return zbiór roślin
     */
    RandomSet<shared_ptr<Plant>> & getPlants();

    /*!
     * Metoda statyczna pozwalająca utworzyć obiekt odpowiedniej klasy ślimaka na podstawie jego typu.
     * @param name - nazwa własna ślimaka
     * @param type - typ ślimaka
     * @param initSize - początkowe pole powierzchni zajmowane przez ślimaka (rozmar)
     * @return utworzony obiekt ślimaka
     */
    static shared_ptr<Snail> initSnail(basic_string<char> name, SnailType type, int initSize);

    /*!
     * Metoda statyczna pozwalająca utworzyć obiekt odpowiedniej klasy rośliny na podstawie jej typu.
     * @param name - nazwa własna rośliny
     * @param type - typ rośliny
     * @param initSize - początkowe pole powierzchni zajmowane przez roślinę (rozmar)
     * @return utworzony obiekt rośliny
     */
    static shared_ptr<Plant> initPlant(basic_string<char> name, PlantType type, int initSize);

private:
    int duration;
    int aquariumWeight;
    int aquariumLength;
    RandomSet<shared_ptr<Snail>> snails;
    RandomSet<shared_ptr<Plant>> plants;

    void validateSimulation(int duration, int aquariumWeight, int aquariumLength);

    void validateSnail(string &name, int initSize);

    void validatePlant(string &name, int initSize);

    void validateAquariumSize(int weight, int length, RandomSet<shared_ptr<Snail>> snails,
                              RandomSet<shared_ptr<Plant>> plants);
};

/*!
 * Operator słuzący do serializacji obiektu buildera.
 */
QDataStream & operator<< (QDataStream& stream, SimulationBuilder& builder);
/*!
 * Operator słuzący do deserializacji obiektu buildera.
 */
QDataStream & operator>> (QDataStream& stream, SimulationBuilder& builder);

/*!
 * Operator słuzący do serializacji zbioru ślimaków.
 */
QDataStream & operator<< (QDataStream& stream, RandomSet<shared_ptr<Snail>>& snails);
/*!
 * Operator słuzący do deserializacji zbioru ślimaków.
 */
QDataStream & operator>> (QDataStream& stream, RandomSet<shared_ptr<Snail>>& snails);

/*!
 * Operator słuzący do serializacji zbioru roślin.
 */
QDataStream & operator<< (QDataStream& stream, RandomSet<shared_ptr<Plant>>& plants);
/*!
 * Operator słuzący do deserializacji zbioru roślin.
 */
QDataStream & operator>> (QDataStream& stream, RandomSet<shared_ptr<Plant>>& plants);


#endif //SLIMAX_SIMULATIONBUILDER_H
