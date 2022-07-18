#include <iostream>
#include <chrono>
#include <iomanip>
#include "Ware.h"
#include "Sortiment.h"




int main() {

    //How many cycles should be tested to calculate the average calculation time
    int cycles = 100000;

    std::cout << std::endl << "Arrays well be sorted from the smallest Serialnummer to the highest! \n\nAverage calculation"
                              " time measured over " << cycles << " cycles" << std::endl;

    bool rand = false;
    std::cout << std::endl << std::setfill('*') << std::setw(120) << "\n" << std::endl;

    std::cout << "Standard mergeSort:" << std::endl;

    for (int r = 0; r < 2; r++) {
        auto regal = new Sortiment;

        //Adding new Ware to testarray, ARRAY_SIZE set in Sortiment.h
        for (int i = 0; i < ARRAY_SIZE; i++) {
            regal->addWare(new Ware());
        }

        //Print out unsorted test array
        std::cout << std::endl << "*** Unsorted array!  \n" << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            regal->readWare(i);
        }

        regal->sort(rand);

        //Print out unsorted test array
        std::cout << std::endl << "*** Sorted array!  \n" << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            regal->readWare(i);
        }

        auto startTime = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < cycles; i++) {
            auto regal_cycle = new Sortiment;
            for (int a = 0; a < ARRAY_SIZE; a++) {
                regal_cycle->addWare(new Ware());
            }
            regal_cycle->sort(rand);
            delete regal_cycle;
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = (endTime - startTime);
        double execTime = (duration.count()) / cycles;

        std::cout << std::endl << "Durchschnittliche Berechnungszeit: " << execTime << " s " << std::endl;

        delete regal;

        if(rand){
            break;
        }

        std::cout << std::endl << std::setfill('*') << std::setw(120) << "\n" << std::endl;

        rand = true;
        std::cout << std::endl << "Rand mergeSort:" << std::endl;
    }
}