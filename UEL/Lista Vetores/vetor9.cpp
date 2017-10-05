#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

void vet9(){
    for(int i = 5000; i <= 7000; i++){
        if(checkPrime(i)) cout << i << "\t";
    }
}
