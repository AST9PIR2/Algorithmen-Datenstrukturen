//
// Created by Pirmin on 27.05.2022.
//

#include <iostream>
#include <iomanip>
#include "Sortiment.h"
#include "exceptions.h"
#include "Algorithms.h"


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
    for (int i = 0; i < (sizeof(waren)/sizeof(waren[0])); i++) {
        delete waren[i];
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

//Selection menu
void Sortiment::sort(int modus) {
    try{
        if(waren[0] != nullptr) {
            switch (modus){
                case 1:
                    quickSort(waren,0,(sizeof(waren)/sizeof(waren[0]))-1);
                    std::cout << std::endl << "Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus" << std::endl;
                    break;
                case 2:
                    bubbleSort(waren,sizeof(waren)/sizeof(waren[0]));
                    std::cout << std::endl << "Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus" << std::endl;
                    break;
                case 3:
                    mergeSort(waren, 0,(sizeof(waren)/sizeof(waren[0]))-1);
                    std::cout << std::endl << "Sortierung alphabetisch nach Bezeichnung mithilfe des mergesort-Algorithmus" << std::endl;
                    break;
                case 4:
                    insertionSortBaseEinkauf(waren, sizeof(waren)/sizeof(waren[0]));
                    std::cout << std::endl << "Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante" << std::endl;
                    break;
                case 5:
                    insertionSortBaseVerkauf(waren, sizeof(waren)/sizeof(waren[0]));
                    std::cout << std::endl << "Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante" << std::endl;
                    break;
                default:
                    throw ErrorSortiment("Requested mode not defined! Please choose sorting option from 1 to 5");
            }
        }else{
            throw ErrorSortiment("Array empty nothing to do!");
        }
        }catch (ErrorSortiment &e) {
        std::cout << std::endl << "*** ErrorSortiment: " << e.what() << " *** " << std::endl << std::endl;
        exit(0);
    }
}

