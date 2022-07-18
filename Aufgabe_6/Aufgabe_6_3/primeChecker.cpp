#include "primeChecker.h"

PrimeChecker::PrimeChecker() = default;

bool PrimeChecker::isPrime(const std::string& method, unsigned long long number) {
    if(method == "bruteforce") {
        return this->bruteforce(number);
    } else if(method == "fermat") {
        return this->fermatsLittleTheorem(number);
    } else {
        std::cerr << "Method not recognized!" << std::endl;
        exit(1);
    }
}

bool PrimeChecker::fermatsLittleTheorem(unsigned long long p) {
    if(p == 1) {
        return this->handleOne();
    }
    if(p == 3) {
    	return true;
    }
    for(int i = 0; i < 30; i++) {
        unsigned long long a = rand() % p;
        if(a==1||a==0) {
        	a+=2 % p;
        }
        unsigned long long result = squareAndMultiply(a, (p-1), p);
        if(result != 1) {
            return false;
        }
    }
    return true;
}

unsigned long long PrimeChecker::squareAndMultiply(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while(exponent > 0) {
        if(exponent & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent >> 1;
    }
    return result;
}



bool PrimeChecker::bruteforce(unsigned long long numberToCheck) {
    if(numberToCheck == 1) {
        return this->handleOne();
    }
    std::vector<unsigned long long> primeNumbers;
    for(unsigned long long i = 2; i < std::ceil(sqrt(numberToCheck)); i++) {
        if((unsigned long long)primeNumbers.size() == 0) {
            primeNumbers.push_back(i);
        } else {
            bool found = false;
            for(unsigned long long j = 0; j < (unsigned long long)primeNumbers.size(); j++) {
                if(i%primeNumbers[j] == 0) { 
                    found = true;
                    break;
                }
            }
            if(found == false) {
                primeNumbers.push_back(i);
            }
        }
    }

    for(unsigned long long i = 0; i < (unsigned long long)primeNumbers.size(); i++) {
        if(numberToCheck%primeNumbers[i] == 0) {
            //std::cout << numberToCheck << " is not a prime number, as it can be divided by " << primeNumbers[i] << "\n";
            return false;
        }
    }
    //std::cout << numberToCheck << " is a prime number!\n";
    return true;
}

bool PrimeChecker::handleOne() {
    srand(time(NULL));
    std::cout << "Diese philosophische Frage werden wir hier nicht beantworten!\n";
    int retVal = rand() % 2;
    return (bool) retVal;
}
