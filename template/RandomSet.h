//
// Created by jpyszko on 27.04.2021.
//

#ifndef SLIMAX_RANDOMSET_H
#define SLIMAX_RANDOMSET_H

#include <set>
#include <random>
#include <chrono>

template<typename T>
/*!
 * Klasa szablonu zbioru umozliwjącego pobieranie losowego elementu
 * @tparam T - typ klasy przetrzymywanej w zbiorze
 */
class RandomSet {

public:
    /*!
     * Konstruktor tworzący nowy obiekt zbioru. W czasie tworzenia ustalane jest ziarno generatora liczb pseudolosowych
     * wykorzystywanych przy losowym zwracaniu elementów zbioru.
     */
    RandomSet() {
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        generator = std::default_random_engine(seed);
    }

    /*!
     * Umożliwa dodanie elementu do istniejącego zbioru.
     * @param element - element dodawany do zbioru
     * @return true - jeśli element został dodany do zbioru, false - jesli element jużistnieje w zbiorze i nie został dodany
     */
    bool add(T element) {
        bool inserted = container.insert(element).second;
        distribution = std::uniform_int_distribution<>(0, container.size() - 1);

        return inserted;
    }

    /*!
     * Funkcja zwracajaca losowy element zbioru. Prodpopodobieństwo wylosowania dla każdego elementów jest jednakowe.
     * @return Wylosowany element zbioru.
     */
    T getRandom() {
        auto it = container.cbegin();
        int random = distribution(generator);
        std::advance(it, random);

        return *it;
    }

    /*!
     * Funkcja zwracająca iterator zbioru wskazujący na pierwszy element. FUnkcja wykorzystywana głownie w pętlach for each.
     * @return Iterator wskazujący pierwszy element.
     */
    auto begin(){
        return container.begin();
    }

    /*!
     * Funkcja zwracająca iterator zbioru wskazujący na ostatni element. FUnkcja wykorzystywana głownie w pętlach for each.
     * @return Iterator wskazujący ostatni element.
     */
    auto end(){
        return container.end();
    }

    /*!
     * Aktualny rozmar zbioru z któego można losować.
     * @return rozmar przechowywanego zbioru
     */
    int size(){
        return container.size();
    }

private:
    std::set<T> container;

    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution;

};

#endif //SLIMAX_RANDOMSET_H
