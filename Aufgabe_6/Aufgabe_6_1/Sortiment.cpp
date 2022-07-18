//
// Created by Pirmin on 27.05.2022.
//

#include <iostream>
#include <iomanip>
#include "Sortiment.h"
#include "exceptions.h"


//Adding a new Ware to array
void Sortiment::addWare(Ware *ware) {
    try{
        //Checking for buffer overflow
        for(auto & i : waren){
            if(i==nullptr){
                i = ware;
                break;
            }else if (waren[ARRAY_SIZE-1] != nullptr){
                throw ErrorSortiment("Storage full, adding Ware not possible!");
            }
        }
    }catch(ErrorSortiment& e){
        std::cout << std::endl << "*** ErrorSortiment: " << e.what() << " *** "   << std::endl << std::endl;
    }
}

//Deleting the whole array
void Sortiment::delete_array() {
    for (auto & i : waren) {
        delete i;
    }

}

//Function to print out Ware
void Sortiment::readWare(int index) {
    try {
        if (waren[index] != nullptr) {
            std::cout << "Bezeichnung: " << std::left << std::setfill(' ') << std::setw(10) <<
                      waren[index]->getBezeichnung() << " Seriennummer: " << std::setfill(' ') << std::setw(10) <<
                      waren[index]->getSeriennummer() << " Gewicht: " << std::setfill(' ') << std::setw(10) <<
                      waren[index]->getGewicht() << " Einkaufspreis: " << std::setfill(' ') << std::setw(10) <<
                      waren[index]->getEinkaufspreis() << " Verkaufspreis: " <<
                      waren[index]->getVerkaufspreis() << std::endl;
        } else {
            throw ErrorSortiment("No element on requested index!");
        }
    } catch (ErrorSortiment &e) {
        std::cout << std::endl << "*** ErrorSortiment: " << e.what() << " *** " << std::endl << std::endl;
    }
}

void Sortiment::sort(bool rand){
    try{
        if(waren[0] != nullptr) {
            mergeSort(waren, 0,(sizeof(waren)/sizeof(waren[0]))-1, rand);
        }else{
            throw ErrorSortiment("Array empty nothing to do!");
        }
    }catch (ErrorSortiment &e) {
        std::cout << std::endl << "*** ErrorSortiment: " << e.what() << " *** " << std::endl << std::endl;
        exit(0);
    }
}



