//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_SORTIMENT_H
#define AUFGABE_1_SORTIMENT_H

#define ARRAY_SIZE 10

#include "Ware.h"
#include "mergesortRand.h"

class Sortiment {

private:
    Ware* waren[ARRAY_SIZE];

public:
    Sortiment() {
        for(auto & i : waren){
            i = nullptr;
        }
    }

    ~Sortiment(){
        this->delete_array();
        //std::cout << std::endl << "All array elements cleared! Memory released!" << std::endl;
    }

    void sort(bool rand);
    //void sort(int modus);

    void addWare(Ware* ware);

    void readWare(int index);

    void delete_array();


};

#endif //AUFGABE_1_SORTIMENT_H
