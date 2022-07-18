//
// Created by Pirmin on 27.05.2022.
//

#include "Ware.h"
#include "exceptions.h"

const std::string &Ware::getBezeichnung() const {
    return bezeichnung;
}

void Ware::setBezeichnung(const std::string &bezeichnung) {
    try{
        for(char i : bezeichnung){
            if((i >= 'A' && i <= 'Z')||(i >= 'a' && i <= 'z')||
            i == '_'){

            }else {
                throw ErrorWare("Setting description failed! Chosen upper/lower case letters A-Z and/or _ ");
            }
        }
        Ware::bezeichnung = bezeichnung;
    }catch (ErrorWare &e) {
        std::cout << std::endl << "*** ErrorWare: " << e.what() << " *** " << std::endl << std::endl;
    }
}


int Ware::getSeriennummer() const {
            return seriennummer;
}

void Ware::setSeriennummer(int seriennummer) {
    try{
        if(seriennummer >= 0 && seriennummer <= 999999 ){
            Ware::seriennummer = seriennummer;
        }else {
            throw ErrorWare("Setting serial number failed! Value out of range!");
        }

    }catch (ErrorWare &e) {
        std::cout << std::endl << "*** ErrorWare: " << e.what() << " *** " << std::endl << std::endl;
    }
}

double Ware::getGewicht() const {
    return gewicht;
}

void Ware::setGewicht(double gewicht) {
    try{
        if(seriennummer >= 0 && seriennummer <= 999999 ){
            Ware::gewicht = gewicht;
        }else {
            throw ErrorWare("Setting weight failed! Value out of range!");
        }

    }catch (ErrorWare &e) {
        std::cout << std::endl << "*** ErrorWare: " << e.what() << " *** " << std::endl << std::endl;
    }
}

double Ware::getEinkaufspreis() const {
    return einkaufspreis;
}

void Ware::setEinkaufspreis(double einkaufspreis) {
    try{
        if(seriennummer >= 0 && seriennummer <= 999999 ){
            Ware::einkaufspreis = einkaufspreis;
        }else {
            throw ErrorWare("Setting purchase price failed! Value out of range!");
        }

    }catch (ErrorWare &e) {
        std::cout << std::endl << "*** ErrorWare: " << e.what() << " *** " << std::endl << std::endl;
    }
}

double Ware::getVerkaufspreis() const {
    return verkaufspreis;
}

void Ware::setVerkaufspreis(double verkaufspreis) {
    try{
        if(seriennummer >= 0 && seriennummer <= 999999 ){
            Ware::verkaufspreis = verkaufspreis;
        }else {
            throw ErrorWare("Setting selling price failed! Value out of range!");
        }

    }catch (ErrorWare &e) {
        std::cout << std::endl << "*** ErrorWare: " << e.what() << " *** " << std::endl << std::endl;
    }
}
