//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_SORTIMENT_H
#define AUFGABE_1_SORTIMENT_H

#define ARRAY_SIZE 10

#include "Ware.h"

class Sortiment {

private:
    Ware* waren[ARRAY_SIZE];

public:
    Sortiment() {
        for(int i = 0; i <ARRAY_SIZE; i++){
            waren[i] = nullptr;
        }
    }

    ~Sortiment(){
        this->delete_array();
        std::cout << "All array elements cleared! Memory released!" << std::endl;
    }

    void sort(int modus);

    void addWare(Ware* ware);

    void readWare(int index);

    void delete_array();


};

#endif //AUFGABE_1_SORTIMENT_H
