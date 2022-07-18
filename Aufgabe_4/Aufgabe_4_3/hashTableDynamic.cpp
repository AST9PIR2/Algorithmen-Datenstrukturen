#include "hashTableDynamic.h"
#include <iostream>
#include <vector>

HashTable::HashTable() {
    this->size = 0;
    this->entries = nullptr;
    this->setHashFunction("mod17");
}

HashTable::HashFunction::HashFunction(std::string name, hashFunctionPtr algorithm, int size) {
    this->name = name;
    this->algorithm = algorithm;
    this->size = size;
}


void HashTable::insert(PbEntry* entry) {

    auto loadFactor = ((2.0/3)*(this->size));

    if (this->numberOfEntries > loadFactor){
        if(this->size == 17){
            this->setHashFunction("mod37");
        }else if (this->size == 37) {
            this->setHashFunction("mod71");
        }else{
            std::cout << "This Programm is not designed to a handle such a load if Data, max inputs of 43 reached!" << std::endl;
            return;
        }
    }

    int hashValue = this->hashFunction(entry->telephoneNumber);
    hashValue = hashValue % this->size;

    if(this->entries[hashValue].key.empty() || this->entries[hashValue].key == "deleted") {
        this->entries[hashValue].key = entry->telephoneNumber;
        this->entries[hashValue].phonebookEntry = entry;
        this->numberOfEntries++;
    } else {
        bool inserted = false;
        int i = (hashValue + 1) % this->size;
        while(!inserted) {
            if(i == hashValue) {
                std::cout << "HashTable full!" << std::endl;
                return;
            }
            if(this->entries[i].key.empty() || this->entries[i].key == "deleted") {
                this->entries[i].key = entry->telephoneNumber;
                this->entries[i].phonebookEntry = entry;
                this->numberOfEntries++;
                inserted = true;
            }
            i = (i + 1) % this->size;
        }
    }
}

void HashTable::print() {
    std::cout << "=====================================" << std::endl;
    for(int i = 0; i < this->size; i++) {
        std::cout << i << " :\t" << this->entries[i].key << std::endl;

    }
    std::cout << "=====================================" << std::endl;
}

void HashTable::setHashFunction(std::string algorithmName) {

    auto flag = false;
    auto temp = this->size;

    for(int i = 0; i < 3; i++) {
            if(this->availableAlgorithms[i].name == algorithmName) {

                std::vector<PbEntry*> speicher;
                this->hashFunction = this->availableAlgorithms[i].algorithm;
                this->size = this->availableAlgorithms[i].size;
                if(this->entries != nullptr) {
                    for(int a = 0; a < temp; a++) {
                        if(this->entries[a].key == "" || this->entries[a].key == "deleted") {
                            continue;
                        }else{
                            speicher.push_back(this->entries[a].phonebookEntry);
                        }
                    }
                    flag = true;
                    delete[] this->entries;
                }

                this->entries = new HashNode[this->size];
                this->numberOfEntries = 1;

                if(flag){
                    for(int a = 0; a < speicher.size(); a++){
                        this->insert(speicher.at(a));
                    }
                }
                return;
            }
        }

    std::cerr << "The Hash Function provided was not found!" << std::endl;
}

const PbEntry* HashTable::search(std::string key) {
    int hashValue = this->hashFunction(key);    //  key is "hashed" and stored in the variable int hashValue
    hashValue = hashValue % this->size;
    int i = 0;
    while(this->entries[hashValue].key != key && this->entries[hashValue].key != "" && i <= this->size) {
        hashValue = (hashValue + 1) % this->size;
        i++;
    }

    if(this->entries[hashValue].key == key) {
        return this->entries[hashValue].phonebookEntry;
    } else {
        std::cout << "Entry with telephone number " << key << " not found!" << std::endl;
        return nullptr;
    }
}

bool HashTable::deleteItem(std::string key) {


    int hashValue = this->hashFunction(key);
    hashValue = hashValue % this->size;

    while(this->entries[hashValue].key != key && this->entries[hashValue].key != "") {
        hashValue = (hashValue + 1) % this->size;
    }

    if(this->entries[hashValue].key == key) {
        this->entries[hashValue].key = "deleted";
        this->entries[hashValue].phonebookEntry = nullptr;
        delete this->entries[hashValue].phonebookEntry;
        this->numberOfEntries--;

        auto loadFactor = ((2.0/3)*(this->size));

        if (this->numberOfEntries < loadFactor){
            if(this->size == 37){
                this->setHashFunction("mod17");
            }else if (this->size == 71) {
                this->setHashFunction("mod37");
            }else{
                std::cout << "This Programm is not designed to a handle such a load if Data, max inputs of 43 reached!" << std::endl;
            }
        }

        return true;
    } else {
        return false;
    }

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
int mod17(std::string telNr) {
    return (int)(std::stol(telNr)%17);
}

int mod37(std::string telNr) {
    return (int)(std::stol(telNr)%37);
}

int mod71(std::string telNr) {
    return (int)(std::stol(telNr)%71);
}
