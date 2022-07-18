//
// Created by Pirmin on 27.05.2022.
//

#include <iostream>
#include "Ware.h"
#include "Sortiment.h"


int main() {

    auto regal = new Sortiment;

    //Adding new Ware to testarray, ARRAY_SIZE set in Sortiment.h
    for(int i = 0; i < ARRAY_SIZE; i++){
        regal->addWare(new Ware());
    }

    //Print out unsorted test array
    std::cout << std::endl << "*** Unsorted array!  " << std::endl;
    for(int i = 0; i < ARRAY_SIZE; i++){
        regal->readWare(i);
    }

    /*
    Selection menu for different sorting Algorithmus

    int modus = 1: Sortierung nach Seriennummer mithilfe des quicksort-Algorithmus
    int modus = 2: Sortierung nach Gewicht mithilfe des bubblesort-Algorithmus
    int modus = 3: Sortierung alphabetisch nach Bezeichnung mithilfe des mergesort-Algorithmus
    int modus = 4: Sortierung nach Einkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
    int modus = 5: Sortierung nach Verkaufspreis mithilfe des insertionsort-Algorithmus in seiner Basisvariante.
    */

    //Trying to run User input
    int modus = 1;
    regal->sort(modus);


    //Print out unsorted test array
    std::cout << std::endl << "*** Sorted array!  " << std::endl;
    for(int i = 0; i < ARRAY_SIZE; i++) {
        regal->readWare(i);
    }

    delete regal;

return 0;
}
