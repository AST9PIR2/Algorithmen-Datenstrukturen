//
// Created by Pirmin on 04.06.2022.
//

#ifndef AUFGABE_2_2_EXTENDEDLISTITEM_H
#define AUFGABE_2_2_EXTENDEDLISTITEM_H

#include <string>

class ExtendedListItem {
public:
    explicit ExtendedListItem(int key);
    [[nodiscard]] std::string toString() const;
    ExtendedListItem* next;
    ExtendedListItem* previous;
    int key;
};

#endif //AUFGABE_2_2_EXTENDEDLISTITEM_H
