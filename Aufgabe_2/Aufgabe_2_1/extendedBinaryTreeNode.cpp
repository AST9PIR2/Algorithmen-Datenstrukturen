//
// Created by Pirmin on 27.05.2022.
//

#include "extendedBinaryTreeNode.h"
#include "exceptions.h"

const std::string &Ware::getBezeichnung() const {
    return bezeichnung;
}

//Not in use but tested
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

//Not in use but tested
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

//Not in use but tested
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

//Not in use but tested
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

//Not in use but tested
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

//Insert according three rules
Ware* Ware::insert(Ware * value) {
    if(value->getVerkaufspreis() > this->getVerkaufspreis()) {
        //std::cout << "***********" << this->getVerkaufspreis() << std::endl;
        if(this->right == nullptr) {
            Ware* temp = value;
            this->right = temp;
            return this->right;
        }
        this->right->insert(value);
    } else {
        if(this->left == nullptr) {
            Ware* temp = value;
            this->left = temp;
            return this->left;
        }
        this->left->insert(value);
    }
    return this;
}

//Deleting and rearranging three
Ware* Ware::deleteItem(Ware * value) {
    Ware* node = this;

    if(node == nullptr) {
        return this;
    } else if(value->getVerkaufspreis() < node->getVerkaufspreis()) {
        node->left = node->left->deleteItem(value);
    } else if(value->getVerkaufspreis() > node->getVerkaufspreis()) {
        node->right = node->right->deleteItem(value);
    } else {
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if(node->left == nullptr) { // only children in right subtree
            Ware* temp = node;
            node = node->right;
            delete temp;
        } else if(this->right == nullptr) { // only children in left subtree
            Ware* temp = node;
            node = node->left;
            delete temp;
        } else { // we have to keep the BST structure, here, we look for the minimum in the right subtree (see lecture)
            Ware* temp = node->right;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            node->key = temp->key;
            node->right = node->right->deleteItem(temp);
        }
    }
    return node;
}