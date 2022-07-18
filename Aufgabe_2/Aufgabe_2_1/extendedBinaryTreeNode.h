//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_WARE_H
#define AUFGABE_1_WARE_H

#include <string>
#include <iostream>
#include <map>
#include "binders.h"


class Ware {

private:
    //Name pool for random creation of products
    std::string name_array[10] = {"Schwert", "Trank", "Kraeuter", "Pilz", "Stein", "Fisch",
                                  "Blume", "Fleisch", "Salz", "Pelz" };
    std::string bezeichnung;
    int seriennummer;
    double gewicht;
    double einkaufspreis;
    double verkaufspreis;

public:

    Ware* key;
    Ware* left;
    Ware* right;

    Ware() : bezeichnung(name_array[std::rand() % 10]), seriennummer(std::rand() % 999999), gewicht(std::rand() % 300),
    einkaufspreis(std::rand() % 1000), verkaufspreis(std::rand() % 2000){
        this->key = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    };

    ~Ware() {};

    const std::string &getBezeichnung() const;

    void setBezeichnung(const std::string &bezeichnung);

    int getSeriennummer() const;

    void setSeriennummer(int seriennummer);

    double getGewicht() const;

    void setGewicht(double gewicht);

    double getEinkaufspreis() const;

    void setEinkaufspreis(double einkaufspreis);

    double getVerkaufspreis() const;

    void setVerkaufspreis(double verkaufspreis);

    Ware* insert(Ware * value);

    Ware* deleteItem(Ware * value);
};
#endif //AUFGABE_1_WARE_H
