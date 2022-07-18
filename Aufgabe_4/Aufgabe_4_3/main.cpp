#include "hashTableDynamic.h"
#include "pbEntry.h"
#include <string>
#include <iostream>
#include "digitSum.h"

int main() {


    std::cout << "Quer- bzw Ziffersummer von 36036 = " << digitSum("36036") << std::endl;
    std::cout << "Speichergroesse von digiSum = " << sizeof(digitSum("36036")) << " bytes" << std::endl;

/*
    PbEntry entry1("3277971", "Norma Noe", "North Lyme Drive 30");
    PbEntry entry2("9928657", "Ashok Kumar", "Lawrence Avenue 24");
    PbEntry entry3("1674792", "Baby Doe", "North Lyme Street 34");
    PbEntry entry4("4991459", "Brett Boe", "North Lyme Road 35 ");
    PbEntry entry5("1990539", "Carla Coe", "Lawrence Road 29");
    HashTable ht;
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry5);
    ht.insert(&entry1);
    ht.insert(&entry2);
    ht.insert(&entry2);
    ht.print();
    ht.deleteItem("1990539");
    ht.deleteItem("1990539");
    ht.print();
*/
}
