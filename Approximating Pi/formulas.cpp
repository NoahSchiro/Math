#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

//Prints each value as it becomes more and more accurate
void liebnitz(unsigned int accuracy) {

    long double pi = 1;

    for (int i = 0; i < accuracy; i++) {

        long double denominator = i * 2 + 3;
        long double fraction = 1 / denominator;

        if(i % 2 == 0) {
            pi -= fraction;
        } else {
            pi += fraction;
        }

        std::cout << pi * 4 << "\n";
    }
}


//GCD needed for euler approximation
int gcd(int a, int b) {
    
    if(b > a) {
        int temp = a;
        a = b;
        b = temp;
    }

    int r = a % b;

    if(r == 0) {
        return b;
    } else {
        return gcd(b,r);
    }
}

void euler(unsigned int accuracy) {
    
    srand(time(NULL));

    //Necessary variables
    std::vector<int> randoms;
    long double coprimes  = 0,
                total = 0;

    //Create random numbers
    for(int i = 0; i < accuracy; i++) {
        int temp = rand() % 10000 + 1;
        randoms.push_back(temp);
    }

    //Loop through the random numbers by two
    for(int i = 0; i < accuracy; i+=2) {

        //If they are co-primes...
        if(gcd(randoms[i], randoms[i+1]) == 1) {
            coprimes++;
        }
        total++;

        long double pi = sqrt((6 * total) / coprimes);
        std::cout << pi << "\n";
    }

}

void chudnovsky() {

} 