//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_EXCEPTIONS_H
#define AUFGABE_1_EXCEPTIONS_H

#include <stdexcept>

class ErrorSortiment : public std::runtime_error {

public:
    using std::runtime_error::runtime_error;
};

class ErrorWare : public ErrorSortiment {
public:
    using ErrorSortiment::ErrorSortiment;
};

#endif //AUFGABE_1_EXCEPTIONS_H
