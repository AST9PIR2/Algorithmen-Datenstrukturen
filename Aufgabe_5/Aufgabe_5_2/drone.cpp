//
// Created by Pirmin on 25.06.2022.
//

#include <valarray>
#include "drone.h"

float Drone::calculateChange(float total, float paid) {

    if(paid < total){
        std::cout << "Not enough money paid! Please add " << total - paid << " Euro" << std::endl;
        return 0;
    }else{
        addCash(paid,availableCashInstances);
        std::cout << paid << " added to Bee!" << std::endl;
        std::cout << "Thank you for your purchase! You will get " << paid-total << " back." << std::endl;
        save = paid-total;
        return save;
    }
}

void Drone::returnChange(float change_temp) {

    if(a > availableCashInstances.size()-1) {

        for(auto i = availableCashInstances.size()-1; i > 0; i-- ){
            if(change_temp >= 0.0099 && availableCashInstances.at(i)->availableAmount >= 1){
                change_temp -= availableCashInstances.at(i)->value;
                availableCashInstances.at(i)->availableAmount --;
                addCash(availableCashInstances.at(i)->value,returnChangeInstances);
                }
        }

        float calcValue = 0;

        for(auto i = 0; i < returnChangeInstances.size(); i++ ){
            if(returnChangeInstances.at(i)->availableAmount>= 1) {
                if (calcValue > save ) {
                    availableCashInstances.at(i)->availableAmount += returnChangeInstances.at(i)->availableAmount;
                    returnChangeInstances.at(i)->availableAmount = 0;
                }
                calcValue += (returnChangeInstances.at(i)->value * returnChangeInstances.at(i)->availableAmount);
            }
        }

        if(change_temp <0  ){
            std::cout << "Warnung: Rueckgeld kann nicht genau herausgegeben werden! Ausbezahlter Betrag ueberschreitet "
                         "den genauen Wert um " << calcValue - save << " !" << std::endl;
        }

        if(calcValue > 0){
            std::cout << "Please take your change! " << calcValue <<  std::endl;
            for(auto & returnChangeInstance : returnChangeInstances){
                if(returnChangeInstance->availableAmount >0){
                    returnChangeInstance->print();
                }
            }
        }


        a = 0;
        return;
    }

    if (change_temp >= availableCashInstances.at(a)->value && availableCashInstances.at(a)->availableAmount >= 1) {
        change_temp -= availableCashInstances.at(a)->value;
        availableCashInstances.at(a)->availableAmount --;
        addCash(availableCashInstances.at(a)->value,returnChangeInstances);
    }else {
        a++;
    }

    returnChange(change_temp);

}

void Drone::addCash(float amount,const std::vector<CashInstance*>& instance) {

    if(b > instance.size()-1) {
        b = 0;
        return;
    }

    if (amount >= instance.at(b)->value) {
        instance.at(b)->availableAmount++;
        amount -= instance.at(b)->value;
    }else {
        b++;
    }

    addCash(amount,instance);

}
