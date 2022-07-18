#include <iostream>
#include <cmath>
#include "numberGenerator.h"

std::string toBinary(int n) {
    if (n==0) return "0";
    else if (n==1) return "1";
    else if (n%2 == 0) return toBinary(n/2) + "0";
    else if (n%2 != 0) return toBinary(n/2) + "1";
    return "";
}

int main() {

    int n = 12;
    int k = 6;
    int L = 15;

    numberGenerator numGen;

    //Creating a pool of primeNumbers (L) with startpoint 2^k
    numGen.primPoolGen(pow(2,k),L);

    double counter = 0;
    double cycles = 1;

    //Test 1
    std::cout << std::endl << "*** Test 1  x=y, test cycles: " << cycles << std::endl;
    {
        for(int i = 0; i < cycles; i++){

            bool xNumbers = false;
            bool modNumbers = false;

            auto xA = 101010111101;
            auto xB = 101010111101;

            auto random = numGen.primPool[rand() % numGen.primPool.size()];

            if(xA == xB){
                xNumbers = true;
            }

            if((xA % random) == (xB % random)){
                modNumbers = true;
            }

            if(xNumbers != modNumbers){
                counter++;
            }
        }

        double temp = (counter/cycles)*100;
        std::cout << "Error counter " << counter << std::endl;
        std::cout << "Error in % " << temp << std::endl;
    }

    counter = 0;
    cycles = pow(10,5);

    //Test 2
    std::cout << std::endl << "*** Test 2  x(random)=y(random), test cycles: " << cycles << std::endl;
    {
        for(int i = 0; i < cycles; i++){

            bool xNumbers = false;
            bool modNumbers = false;

            auto xA = stoll(toBinary(rand() % int(pow(2,n))));
            auto xB = stoll(toBinary(rand() % int(pow(2,n))));

            auto random = numGen.primPool[rand() % numGen.primPool.size()];

            if(xA == xB){
                xNumbers = true;
            }

            if((xA % random) == (xB % random)){
                modNumbers = true;
            }

            if(xNumbers != modNumbers){
                counter++;
            }
        }

        double temp = (counter/cycles)*100;
        std::cout << "Error counter " << counter << std::endl;
        std::cout << "Error in % " << temp << std::endl;
    }


}