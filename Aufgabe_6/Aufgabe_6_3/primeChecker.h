#include <string>
#include <iostream>
#include <vector>
#include <cmath>

class PrimeChecker {
    private:
        bool fermatsLittleTheorem(unsigned long long p);
        unsigned long long squareAndMultiply(unsigned long long base, unsigned long long exponent, unsigned long long mod);
        bool bruteforce(unsigned long long number);
        bool handleOne();

public:
    PrimeChecker();
    //bruteForce();
    bool isPrime(const std::string& method, unsigned long long number);
};