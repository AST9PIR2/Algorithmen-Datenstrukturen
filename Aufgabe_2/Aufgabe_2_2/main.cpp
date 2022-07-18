#include "doublyLinkedList.h"

int main() {

    DoublyLinkedList list;
    list.insertSorted(5);
    list.insertSorted(7);
    list.insertSorted(19);
    list.insertSorted(23);
    list.insertSorted(1);
    list.insertSorted(9);
    list.insertSorted(17);
    list.insertSorted(17);
    list.insertSorted(42);
    list.insertSorted(8);


    std::cout << "Printing out list" << std::endl;
    list.print();

    DoublyLinkedList list2;
    list2.insertSorted(11);
    list2.insertSorted(19);
    list2.insertSorted(14);

    std::cout << "Printing out list2" << std::endl;
    list2.print();

    list.append(&list2);
    std::cout << "Printing out list2 append to list" << std::endl;
    list.print();

    std::cout << "Printing out list2 (should be empty, because its append to list)" << std::endl;
    list2.print();

    DoublyLinkedList list3;
    list3.insertSorted(2);
    list3.insertSorted(3);
    list3.insertSorted(4);

    std::cout << "Printing out list3" << std::endl;
    list3.print();

    list.splice(&list3, 1);
    std::cout << "Printing out list3 spliced in to list on position 1" << std::endl;
    list.print();

    std::cout << "Printing out list3 (should be empty, because its spliced into list)" << std::endl;
    list3.print();


    list.deleteItem(42);
    std::cout << "Printing out list without 42" << std::endl;
    list.print();

}