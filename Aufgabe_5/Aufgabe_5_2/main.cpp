#include <iostream>
#include "drone.h"

int main() {

    { //Test with Bee1
        Drone mechanicalBee;

        std::cout << std::endl << "****************************--Test_1--*********************************" << std::endl << std::endl;

        //Fill up the Bee with change and make it ready for her shift.
        mechanicalBee.addCash(2123.21, mechanicalBee.availableCashInstances);
        std::cout << std::endl << "Current balance mechanicalBee!" << std::endl;

        for(auto & availableCashInstance : mechanicalBee.availableCashInstances){
            availableCashInstance->print();
        }

        mechanicalBee.returnChange(mechanicalBee.calculateChange(122, 124.13));
        std::cout << std::endl << "***********************************************************************" << std::endl << std::endl;
    }


    { //Test with Bee2
        Drone mechanicalBee;

        std::cout << std::endl << "****************************--Test_2--*********************************" << std::endl << std::endl;

        //Fill up the Bee with change and make it ready for her shift.
        mechanicalBee.addCash(1211.45, mechanicalBee.availableCashInstances);
        mechanicalBee.returnChange(mechanicalBee.calculateChange(50, 124.11));

        std::cout << std::endl << "***********************************************************************" << std::endl << std::endl;
    }

    { //Test with Bee3
        Drone mechanicalBee;

        std::cout << std::endl << "****************************--Test_3--*********************************" << std::endl << std::endl;

        //Fill up the Bee with change and make it ready for her shift.
        mechanicalBee.addCash(2123.21, mechanicalBee.availableCashInstances);
        mechanicalBee.returnChange(mechanicalBee.calculateChange(200, 124.13));

        std::cout << std::endl << "***********************************************************************" << std::endl << std::endl;
    }



}
