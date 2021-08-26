//
// Created by jpyszko on 15.08.2021.
//

#ifndef SLIMAX_VALIDATIONEXCEPTION_H
#define SLIMAX_VALIDATIONEXCEPTION_H


#include <exception>
#include <string>

using namespace std;
/*!
 * Typ wyliczeniowy możliwych blędów podczas dodawania obiektów symluacji.
 */
enum ExceptionType{
    EMPTY_SNAIL_NAME,
    INVALID_SNAIL_SIZE,
    EMPTY_PLANT_SIZE,
    INVALID_PLANT_SIZE,
    INVALID_DURATION,
    INVALID_AQUARIUM_SIZE,
    AQUARIUM_TOO_SMALL,
    INVALID_SNAIL_TYPE,
    INVALID_PLANT_TYPE,
    EMPTY_SNAILS_LIST,
    EMPTY_PLANTS_LIST

};

/*!
 * Klasa wyjątku rzucanego przez SimulationBuilder w przypadku stwierdzenia nieporawnych danych.
 */
class ValidationException: public std::exception{

public:
    /*!
     * Konstruktor tworzący klasę
     * @param why - anglojęzyczny techniczny opis blędu
     * @param type - rodzaj blędu
     */
    ValidationException(const char* why, ExceptionType type);

    /*!
     * Metoda przeciązona z std::exception. Zwraca techniczny opis blędu.
     */
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

    /*!
     * Metoda dostępowa dla rodzaju zgłoszonego blędu.
     * @return rodzaj błędu
     */
    ExceptionType getType();

private:

    string reason;
    ExceptionType type;

};


#endif //SLIMAX_VALIDATIONEXCEPTION_H
