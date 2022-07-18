//
// Created by Pirmin on 04.06.2022.
//

#include "ExtendedListItem.h"

std::string ExtendedListItem::toString() const {
    return std::to_string(this->key);
}

ExtendedListItem::ExtendedListItem(int key) {
    this->key = key;
    this->next = nullptr;
    this->previous = nullptr;
}
