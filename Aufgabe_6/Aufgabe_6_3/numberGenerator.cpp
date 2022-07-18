//
// Created by Pirmin on 04.07.2022.
//

#include "numberGenerator.h"

PrimeChecker prim;

void numberGenerator::primPoolGen(int start, int end) {

    while (primPool.size() < end) {
        if (prim.isPrime("fermat", start)) {
            primPool.push_back(start);
        }
        start++;
    }
}
