//
// Created by Pirmin on 04.06.2022.
//

#ifndef AUFGABE_2_2_DOUBLYLINKEDLIST_H
#define AUFGABE_2_2_DOUBLYLINKEDLIST_H

#include "ExtendedListItem.h"
#include <iostream>


struct DoublyLinkedList {
public:
    DoublyLinkedList();

    ExtendedListItem* head;
    ExtendedListItem* tail;
    void insertSorted(int key);

    void append(DoublyLinkedList* appendingList);
    void splice(DoublyLinkedList* insertingList, int position) const;
    void insertAtStart(int key);
    void insertAtEnd(int key);
    void deleteItem(int key);
    void print() const;

private:


};

#endif //AUFGABE_2_2_DOUBLYLINKEDLIST_H
