#include <cmath>
#include <vector>

/*

*/

std::vector<int> primeFactor(int num) {
    std::vector<int> pf;

    //Start with our smallest prime number, two
    while(num % 2 == 0){
        pf.push_back(2);
        num /= 2;
    }

    for(int i = 3; i < sqrt(num); i += 2){
        
        while(num % i == 0) {
            pf.push_back(i);
            num /= i;
        }
    }

    if(num > 2) {
        pf.push_back(num);
    }

    return pf;
}