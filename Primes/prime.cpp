#include <cmath>
#include <vector>

bool primality(int num) {

    bool isPrime = true;

    if(num < 3) {
        return false;
    }

    for(int i = 2; i <= sqrt(num); i++) { 
        if(num % i == 0) {
            isPrime = false;
        }
    }

    return isPrime;
}

std::vector<int> primesInRange(int start, int stop) {
    
    std::vector<int> primes;

    for(int i = start; i < stop; i++){

        if(primality(i)) {
            primes.push_back(i);
        }
    }

    return primes;
}

