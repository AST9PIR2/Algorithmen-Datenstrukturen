#include "hashTableChaining.h"
#include <iostream>

#include <algorithm>
#include <utility>

HashTable::HashTable() {
    this->size = 0;
    this->entries = nullptr;
    this->setHashFunction("myhash");
}

[[maybe_unused]] HashTable::HashFunction::HashFunction(std::string name, hashFunctionPtr algorithm, int size) {
    this->name = std::move(name);
    this->algorithm = algorithm;
    this->size = size;
}


void HashTable::insert(Ware* entry) const {

    HashNode newHashNode(entry->getBezeichnung(),entry);
    auto hashValue = int(entry->getBezeichnung()[0]) + int(entry->getBezeichnung()[1]);

    hashValue = hashValue % this->size;

    this->entries[hashValue].push_back(newHashNode);

}

void HashTable::print() const {
    std::cout << "=====================================" << std::endl;
    for (int i = 0; i < this->size; i++) {
        std::cout << i << " :\t";

        std::list<HashNode>::iterator list;
        for (list = this->entries[i].begin(); list != this->entries[i].end(); ++list) {
            std::cout << list->key << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "=====================================" << std::endl;
}


void HashTable::setHashFunction(const std::string& algorithmName) {
    for(int i = 0; i < 4; i++) {
        if(this->availableAlgorithms[i].name == algorithmName) {
            this->hashFunction = this->availableAlgorithms[i].algorithm;
            this->size = this->availableAlgorithms[i].size;
            delete[] this->entries;
            this->entries = new std::list<HashNode>[this->size];
            return;
        }
    }

    std::cerr << "The Hash Function provided was not found!" << std::endl;
}

const Ware* HashTable::search(std::string key) const {
    auto hashValue = int(key[0]) + int(key[1]);
    hashValue = hashValue % this->size;
    std::list<HashNode>::iterator list;
    for(list = this->entries[hashValue].begin(); list != this->entries[hashValue].end(); ++list) {
        if(list->key == key)
        {
            return list->wareEntry;
        }
    }
    return nullptr;
}

bool HashTable::deleteItem(std::string key) const {
    auto hashValue = int(key[0]) + int(key[1]);
    hashValue = hashValue % this->size;


    std::list<HashNode>::iterator list;
    for (list = this->entries[hashValue].begin(); list != this->entries[hashValue].end(); ++list) {
        if (list->key == key) {
            this->entries[hashValue].erase(list);
            return true;
        }
    }
    return false;
}


/*  algorithm that "hashes" the last digit of a number  */
int lastNumber(std::string telNr) {
    if(telNr.length() <=0) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 1 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-1, telNr.end()));
}

/*  algorithm that "hashes" the first three digits of a number  */
int firstThreeNumbers(std::string telNr) {
        if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.begin(), telNr.begin()+3));
}

/*  algorithm that "hashes" the last three digits of a number  */
int lastThreeNumbers(std::string telNr) {
    if(telNr.length() < 3) {
        std::cerr << "Number '" << telNr << "' does not contain enough digits. At least 3 needed!";
        exit(1);
    }
    return std::stoi(std::string(telNr.end()-3, telNr.end()));
}

/*  algorithm that "hashes" the through mod17  */
int mod17(const std::string& telNr) {
    return (int)(std::stol(telNr)%17);
}

