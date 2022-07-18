//
// Created by Pirmin on 25.06.2022.
//

#ifndef AUFGABE_5_2_DRONE_H
#define AUFGABE_5_2_DRONE_H

#include <iostream>
#include <vector>
#include "cashInstance.h"

class Drone{
public:

    int a = 0;
    int b = 0;
    float save =0;

    std::vector<CashInstance*> availableCashInstances;
    std::vector<CashInstance*> returnChangeInstances;

    float Euro[15] = {500.0,200.0,100,50,20,10,5,2,1,0.5,0.2,0.1,
                      0.05, 0.02,0.01};

    Drone(){

        for(int i = 0; i < 15; i++){
            availableCashInstances.emplace_back(new CashInstance(Euro[i],0));
            returnChangeInstances.emplace_back(new CashInstance(Euro[i],0));
        }

    };

    ~Drone() = default;

    float calculateChange(float total, float paid);
    void returnChange(float change);
    void addCash(float amount, const std::vector<CashInstance*>& instance);



};

#endif //AUFGABE_5_2_DRONE_H
