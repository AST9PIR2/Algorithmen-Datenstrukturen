#ifndef AUFGABE_5_3_ITEM_H
#define AUFGABE_5_3_ITEM_H

#include <string>

/*  Class for Item, containing name (string), value (int) and weight (int).
    There is also a constructor that can be called with all member variables to
    increase convenience. The getRatio() function returns the value/weight ratio
*/
class Item {
    public:
        std::string name;
        int weight;
        float value;
        Item(std::string name, int weight, int value):name(name), weight(weight), value(value){};
        float getRatio();
};

#endif