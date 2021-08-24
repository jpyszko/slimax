//
// Created by jpyszko on 15.08.2021.
//

#ifndef SLIMAX_VALIDATIONEXCEPTION_H
#define SLIMAX_VALIDATIONEXCEPTION_H


#include <exception>
#include <string>

using namespace std;

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

class ValidationException: public std::exception{
private:

    string reason;
    ExceptionType type;

public:
    ValidationException(const char* why, ExceptionType type);

    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

    ExceptionType getType();

};


#endif //SLIMAX_VALIDATIONEXCEPTION_H
