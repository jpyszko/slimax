//
// Created by jpyszko on 15.08.2021.
//

#include "validationexception.h"


ValidationException::ValidationException(const char *why, ExceptionType type) : reason(why), type(type) {}

const char *ValidationException::what() const noexcept {
    return reason.c_str();
}

ExceptionType ValidationException::getType() {
    return type;
}
