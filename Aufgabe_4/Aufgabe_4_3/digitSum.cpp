//
// Created by Pirmin on 19.06.2022.
//
#include <iostream>
#include "digitSum.h"
//#include "string.h"

//Ich verstehe die Farge nicht bzw bin ich mir nicht sicher, ob es wirklich um Speichergrössen geht.
//Prämisse die Frage bezieht sich auf die Speichergroesse!

//Die Funktion brauch 4 bytes Speicher.
//Wir verwenden int, weil das so vorgegeben ist und haben somit für die 7ben Zahlen mehr als ausreichend Speicher.
//Für die 7 Zahlen wäre auch schon ein char genug, da wir maximal auf 9+9+9+9+9+9+9 = 63 kommen

int digitSum(std::string telNr){
    int temp = 0;

    for(int i = 0; i < telNr.length(); i++){
        temp += telNr[i]-48;
    }

    return temp;

}
