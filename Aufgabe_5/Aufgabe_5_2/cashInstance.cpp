//
// Created by Pirmin on 25.06.2022.
//

#include "cashInstance.h"

void CashInstance::print() const {
    if(availableAmount > 0){
        std::cout << "Value: " << std::setprecision(2) << std::fixed << value << "\tamount: " << availableAmount << std::endl;
    }
}
