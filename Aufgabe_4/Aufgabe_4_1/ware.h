//
// Created by Pirmin on 27.05.2022.
//

#ifndef AUFGABE_1_WARE_H
#define AUFGABE_1_WARE_H

#include <string>
#include <iostream>


class Ware {

private:
    //Name pool for random creation of products
    std::string name_array[20] = {"Schwert", "Trank", "Krauter", "Pilz", "Stein", "Fisch",
                                  "Blume", "Fleisch", "Salz", "Pelz", "Messer", "Kerze",
                                  "Gold", "Schild", "Harpune", "Holz", "Brot", "Apfel",
                                  "Lampe", "Schlussel"};
    std::string bezeichnung;
    int seriennummer;
    double gewicht;
    double einkaufspreis;
    double verkaufspreis;

public:

    Ware() : bezeichnung(name_array[std::rand() % 20]), seriennummer(std::rand() % 999999), gewicht(std::rand() % 300),
    einkaufspreis(std::rand() % 1000), verkaufspreis(std::rand() % 2000){
    }

    Ware(std::string bezeichnung, int seriennummer, double gewicht, double einkaufspreis, double verkaufspreis){
        this->bezeichnung = bezeichnung;
        this->seriennummer = seriennummer;
        this->gewicht = gewicht;
        this->einkaufspreis = einkaufspreis;
        this->verkaufspreis = verkaufspreis;
    };

    ~Ware() = default;

    [[nodiscard]] const std::string &getBezeichnung() const;

    void setBezeichnung(const std::string &bezeichnung);

    [[nodiscard]] int getSeriennummer() const;

    void setSeriennummer(int seriennummer);

    [[nodiscard]] double getGewicht() const;

    void setGewicht(double gewicht);

    [[nodiscard]] double getEinkaufspreis() const;

    void setEinkaufspreis(double einkaufspreis);

    [[nodiscard]] double getVerkaufspreis() const;

    void setVerkaufspreis(double verkaufspreis);

};
#endif //AUFGABE_1_WARE_H
