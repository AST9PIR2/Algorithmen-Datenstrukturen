#include "hashTableChaining.h"
#include <string>
#include <iostream>

int main() {
    srand((unsigned)time(0));
    HashTable ht;
    ht.setHashFunction("myhash");


    Ware entry1("Stein", 000000, 10, 10, 10 );
    Ware entry2("Fisch", 000001, 10, 10, 10 );
    Ware entry3("Lampe", 000002, 10, 10, 10 );
    Ware entry4("Vogel", 000003, 10, 10, 10 );
    Ware entry5("Kerze", 000004, 10, 10, 10 );
    Ware entry6("Ruder", 000005, 10, 10, 10 );

    for(int i = 0; i < 300; i++){
        ht.insert(new Ware());
    }

    ht.insert(&entry1);
    ht.insert(&entry1);
    ht.insert(&entry6);
    ht.insert(&entry2);
    ht.insert(&entry3);
    ht.insert(&entry4);
    ht.insert(&entry5);

    std::cout << ht.search("Ruder") << std::endl;
    std::cout <<  ht.deleteItem("Ruder") << std::endl;


    ht.print();
    std::cout << ht.search("Ruder") << std::endl;


    // ht.setHashFunction("mod17");
    // ht.insert(&entry1);
    // ht.insert(&entry2);
    // ht.insert(&entry3);
    // ht.insert(&entry4);
    // ht.insert(&entry5);
    // ht.print();

    // const Ware* s1 = ht.search("3277971");
    // std::cout << s1->toString();
    
    // bool test = ht.deleteItem("3277971");
    // std::cout << test << std::endl;
    // bool test2 = ht.deleteItem("3277971");
    // std::cout << test2 << std::endl;
}
