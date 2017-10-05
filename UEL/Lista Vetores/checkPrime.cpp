#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

bool checkPrime(int p){
    for(int i = 2; i < sqrt(p) + 1; i++){
        if(p % i == 0) return false;
    }
    return true;
}
