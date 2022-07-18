#include <string>
#include <list>
#include <utility>
#include "ware.h"

typedef int (*hashFunctionPtr)(std::string);    //  typedefinition of a pointer for a hashfunction; they all need conform to the guideline: int <functionName>(std::string <param>) 
int lastNumber(std::string telNr);              //  hash algorithm that uses only the last digit of a given telNr
int firstThreeNumbers(std::string telNr);       //  hash algorithm that uses the first three digits of a given telNr
int lastThreeNumbers(std::string telNr);        //  hash algorithm that uses the last three digits of a given telNr
int mod17(const std::string& telNr);                   //  hash algorithm that takes a given telNr mod17

class HashTable {
    private:

        class HashFunction {                    //  private inner class to make hash functions managable
            public:
                int size= 100;
                std::string name;
                hashFunctionPtr algorithm;

            [[maybe_unused]] HashFunction(std::string name, hashFunctionPtr algorithm, int size);    //  constructor
        };

        HashFunction availableAlgorithms[1] = { {"myhash", firstThreeNumbers, 100}};

        class HashNode {                    //  private inner class for HashNodes that have a key (which will be the telephone number) and a value of type Ware
            public:
            HashNode(std::string key, Ware* wareEntry) {
                this->key = std::move(key);
                this->wareEntry = wareEntry;
            }

            std::string key;
                Ware *wareEntry;
        };

    public:
        int size;                       //  m in lecture
        int numberOfEntries{};            //  n in lecture
        std::list<HashNode> *entries;
        hashFunctionPtr hashFunction{};   //  pointer to the hash algorithm used is stored in a private variable of type hashFunctionPtr - see beginning of this file


        void insert(Ware* entry) const;
        [[nodiscard]] const Ware* search(std::string key) const;
        [[nodiscard]] bool deleteItem(std::string key) const;
        void print() const;
        void setHashFunction(const std::string& name);

        HashTable();                        //  default constructor
};