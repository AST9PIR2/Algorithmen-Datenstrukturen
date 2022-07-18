//
// Created by Pirmin on 25.06.2022.
//

#ifndef AUFGABE_5_2_CASHINSTANCE_H
#define AUFGABE_5_2_CASHINSTANCE_H

#include <iostream>
#include <iomanip>


class CashInstance {

public:

    float value;
    int availableAmount;

    CashInstance(float value, int availableAmount){
        this->value = value;
        this->availableAmount = availableAmount;
    };

    ~CashInstance()= default;;

    //Funktion ist only working for if there is an amount > 0
    void print() const;

};


#endif //AUFGABE_5_2_CASHINSTANCE_H
