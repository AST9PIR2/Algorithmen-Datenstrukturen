//
// Created by Pirmin on 04.06.2022.
//


#include <iomanip>
#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::insertAtStart(int key) {
    auto* temp = new ExtendedListItem(key);

    // set the pointers correctly
    if(this->head == nullptr) {
        this->head = temp;
        this->head->next = nullptr;
        this->head->previous = nullptr;
        this->tail = temp;
        this->tail->previous = nullptr;
        this->tail->next = nullptr;
    } else {
        this->head->previous = temp;
        temp->next = this->head;
        temp->previous = nullptr;
        this->head = temp;
    }
}

void DoublyLinkedList::insertAtEnd(int key) {
    auto* temp = new ExtendedListItem(key);

    // set the pointers correctly
    if(this->head == nullptr) {
        this->head = temp;
        this->head->next = nullptr;
        this->head->previous = nullptr;
        this->tail = temp;
        this->tail->previous = nullptr;
        this->tail->next = nullptr;
    } else {
        temp->previous = this->tail;
        temp->next = nullptr;
        this->tail->next = temp;
        this->tail = temp;
    }
}

void DoublyLinkedList::insertSorted(int key) {
    ExtendedListItem* prev = nullptr;
    ExtendedListItem* current = this->head;

    //create the new extendedListItem
    auto* newItem = new ExtendedListItem(key);

    // list is empty OR new is smaller than head->key => insert at front
    if(this->head == nullptr || key < this->head->key) {
        this->insertAtStart(key);
        return;
    }

    // new key is larger than tail->key=> insert at end
    if(key > this->tail->key) {
        this->insertAtEnd(key);
        return;
    }
    // search for correct position to insert
    bool inserted = false;
    while(!inserted) {
        prev = current;
        current = current->next;

        if(key < current->key) {

            // set the pointers correctly
            prev->next = newItem;
            newItem->previous = prev;
            newItem->next = current;
            current->previous = newItem;

            inserted = true;
        } else {
            continue;
        }
    }
}

void DoublyLinkedList::print() const {
    ExtendedListItem* temp = this->head;

    if(temp == nullptr) {
        std::cout << "<Empty List>" << std::endl << std::endl;
        return;
    }

    while(temp != nullptr) {
        std::cout << "Obejektpointer: " << temp << "    Objekt: "<< std::left << std::setfill(' ') <<
        std::setw(4) << temp->toString() << "previous objekt: "<< temp->previous << " next objekt: " << temp->next;

        if(temp->next != nullptr) {
            std::cout << " -> " << std::endl;
        }
        temp = temp->next;
    }
    std::cout << std::endl << std::endl;
}

void DoublyLinkedList::append(DoublyLinkedList* appendingList) {
    if(appendingList->head != nullptr && appendingList->tail != nullptr) {

        // set the pointers correctly
        this->tail->next = appendingList->head;
        appendingList->head->previous = this->tail;
        this->tail = appendingList->tail;



        // clear the inserting list
        appendingList->head = nullptr;
        appendingList->tail = nullptr;
    }
}

void DoublyLinkedList::splice(DoublyLinkedList* insertingList, int position) const {
    if((insertingList->head != nullptr) & (insertingList->tail != nullptr)) {
        ExtendedListItem* prev = nullptr;
        ExtendedListItem* current = this->head;

        // find the correct position to start spliceing
        for(int i = 0; i < position; i++) {
            prev = current;
            current = current->next;
        }
        // set the pointers correctly
        prev->next = insertingList->head;
        insertingList->head->previous = prev;
        insertingList->tail->next = current;
        current->previous = insertingList->tail;

        // clear the inserting list
        insertingList->head = nullptr;
        insertingList->tail = nullptr;
    }
}

void DoublyLinkedList::deleteItem(int key) {
    ExtendedListItem* current = this->head;

    while(current != nullptr) {
        if(key == current->key) {

            // If item is start of list
            if(current->previous == nullptr) {
                current->next->previous = nullptr;
                this->head = current->next;
            } else {
                current->previous->next = current->next;
            }

            // If item is end of list
            if(current->next == nullptr) {
                current->previous->next = nullptr;
                this->tail = current->previous;
            } else {
                current->next->previous = current->previous;
            }

            delete current;

            //Return in void... needed here otherwise it will print out "Item not found"
            return;
        }
        current = current->next;
    }
    std::cout << "Item not found!" << std::endl;
}


