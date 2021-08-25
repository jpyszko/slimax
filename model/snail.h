//
// Created by jpyszko on 09.03.2021.
//

#ifndef SLIMAX_SNAIL_H
#define SLIMAX_SNAIL_H

#include <string>
#include <map>
#include "plant.h"

using namespace std;

/*!
 * Typ wyliczeniowy określający typ ślimaka. Zawiera też specjalną techniczną wartość niezidentyfikowanego ślimaka - UNKNOWN_SNAIL
 */
enum SnailType {
    ROMAN_SNAIL,
    TURKISH_SNAIL,
    GARDEN_SNAIL,
    UNKNOWN_SNAIL
};
/*!
 * Abstrakcyjna klasa ślimaka. Zawiera pola i metody wspołne dla wyszystkich typów slimaków w tym pole określające jego typ.
 */
class Snail {

public:

    /*!
     * W pełni wirtualna (abstrakcyjna) metoda określająca nawyki żywieniowe ślimaka i odpowiedz na podaną roślinę.
     * @param plant - roślina podana ślimakowi do zjedzenia
     */
    virtual void eat(Plant &plant) = 0;

    /*!
     * Metoda dostępowa dla nazwy ślimaka.
     * @return zdefinowana nazwa ślimaka
     */
    string getName();

    /*!
     * Metoda dostępowa dla typu ślimaka.
     * @return zdefiniowany typ ślimaka
     */
    SnailType getType();

    /*!
     * Metoda dostępowa dla aktualnego pola powierzchni (rozmaru) zajmowanego przez ślimaka.
     * @return aktualne pole powierzchni zajmowane przez ślimaka
     */
    int getSize();

    /*!
     * Definicja operatora "<" wykorzystywanego przez RandomSet do ustalenia porządku (kolejności) elementów oraz wykrywania dublikatów.
     * Powyższe sprawdzane jest jedynie na podstawie nazwy ślimaka.
     * @param right - slimak (element zbioru) z którym obecny ślimak jest porónywany
     * @return true - jeśli obecny element powienen występować przed elementem right, false - w przeciwnym przypadku
     */
    bool operator<(const Snail &right) const {
        return name < right.name;
    }

    /*!
     * Wirtualny destruktor uruchamiany przez klasy dziedzicące.
     */
    virtual ~Snail() = default;

    /*!
     * Metoda statczna pozwalająca przetłumaczyć typ wyliczeniowy ślimaka na jego polską nazwę możliwą do wyświetlenia.
     * @param snailType - typ slimaka który ma zostać przetłumaczony
     * @return polska nazwa ślimaka
     */
    static string typeToString(SnailType snailType);

    /*!
     * Metoda statyczna pozwalająca przetułmaczyć polskąwyświetlaną nazwę na jego odpowiednik w typie wyliczeniowym
     * @param snailTypeName - polska nazwa ślimaka
     * @return typ ślimaka jako typ wyliczeniowy SnailType
     */
    static SnailType stringToType(string snailTypeName);

protected:
    /*!
     * Konstruktor klasy do wykorzystania przez klasy potomne.
     * @param name - nazwa własna ślimaka
     * @param type - typ ślimaka jako SnailType
     * @param initSize - początkowe pole powierznich zajmowane przez ślimaka (rozmar)
     */
    Snail(string name, SnailType type, int initSize);

    /*!
     * Metoda dostępowa pozwalająca na ustawienie aktualnego pola powierzchni ślimaka.
     * @param size - aktualne pole powierzchni (rozmar)
     */
    void setSize(int size);

private:
    const string name;
    const SnailType type;
    int size;

    const static map<SnailType, string> typeNames;

};

#endif //SLIMAX_SNAIL_H
