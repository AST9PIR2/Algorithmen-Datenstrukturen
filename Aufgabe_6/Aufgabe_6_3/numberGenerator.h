//
// Created by Pirmin on 04.07.2022.
//

#ifndef AUFGABE_6_3_NUMBERGENERATOR_H
#define AUFGABE_6_3_NUMBERGENERATOR_H

#include <vector>
#include "primeChecker.h"

class numberGenerator {
private:

public:

    std::vector<int> primPool;

    void primPoolGen(int start, int end);

};

#endif //AUFGABE_6_3_NUMBERGENERATOR_H
