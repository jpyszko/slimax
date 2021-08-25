//
// Created by jpyszko on 18.07.2021.
//

#ifndef SLIMAX_PLANT_H
#define SLIMAX_PLANT_H

#include <string>
#include <map>

using namespace std;

/*!
 * Typ wyliczeniowy określający typ rośliny. Zawiera też specjalną techniczną wartość niezidentyfikowanej rośliny - UNKNOWN_PLANT
 */
enum PlantType {
    LETTUCE,
    GRASS,
    CARROT,
    UNKNOWN_PLANT
};

/*!
 * Abstrakcyjna klasa rośliny. Zawiera pola i metody wspołne dla wyszystkich typów roślin w tym pole określające jego typ.
 */
class Plant {

public:
    /*!
     * W pełni wirtualna (bstrakcyjna) metoda określająca sposób rosnięcia rośliny.
     */
    virtual void grow() = 0;

    /*!
     * Metoda opisujące reakcjęrośliny na ugryzienie jej przez ślimaka. Roślina pomniejsza się o wartość ugryzienia ślimaka.
     * Jeśli rośłina jest mniejsza niż ugryzienie ślimaka wtedy wtedy wartość ugryzienia jest równa całej rośłinie.
     * @param biteSize - rozmar ugryzienia ślimaka
     * @return rzeczywisty rozmar ugryzienia
     */
    int bite(int biteSize);

    /*!
     * Metoda dostępowa dla nazwy rośliny.
     * @return zdefinowana nazwa rośliny
     * */
    string getName();

    /*!
     * Metoda dostępowa dla typu rośliny.
     * @return zdefiniowany typ rośłiny
     */
    PlantType getType();

    /*!
     * Metoda dostępowa dla aktualnego pola powierzchni (rozmaru) zajmowanego przez rośłinę.
     * @return aktualne pole powierzchni zajmowane przez roślinę
     */
    int getSize();

    /*!
     * Definicja operatora "<" wykorzystywanego przez RandomSet do ustalenia porządku (kolejności) elementów oraz wykrywania dublikatów.
     * Powyższe sprawdzane jest jedynie na podstawie nazwy rośliny.
     * @param right - roślina (element zbioru) z którym obecna roślina jest porónywana
     * @return true - jeśli obecny element powienen występować przed elementem right, false - w przeciwnym przypadku
     * */
    bool operator<(const Plant &right) const {
        return name < right.name;
    }

    /*!
     * * Wirtualny destruktor uruchamiany przez klasy dziedzicące.
     * */
    virtual ~Plant() = default;

    /*!
     * Metoda statczna pozwalająca przetłumaczyć typ wyliczeniowy rośliny na jej polską nazwę możliwą do wyświetlenia.
     * @param plantType - typ rośliny, która ma zostać przetłumaczony
     * @return polska nazwa rośliny
     * */
    static string typeToString(PlantType plantType);

    /*!
     * Metoda statyczna pozwalająca przetułmaczyć polskąwyświetlaną nazwę na jego odpowiednik w typie wyliczeniowym
     * @param plantTypeName - polska nazwa rośliny
     * @return typ rośliny jako typ wyliczeniowy PlantType
     */
    static PlantType stringToType(string plantTypeName);

protected:
    /*!
     * Konstruktor klasy do wykorzystania przez klasy potomne.
     * @param name - nazwa własna rośliny
     * @param type - typ rośłiny jako PlantType
     * @param initSize - początkowe pole powierznich zajmowane przez roślinę (rozmar)
     */
    Plant(string name, PlantType type, int initSize);

    /*!
     * Metoda dostępowa pozwalająca na ustawienie aktualnego pola powierzchni rośliny.
     * @param size - aktualne pole powierzchni (rozmar)
     */
    void setSize(int size);

private:
    const string name;
    const PlantType type;
    int size;

    const static map<PlantType, string> typeNames;

};


#endif //SLIMAX_PLANT_H
