#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

int calcNumDivisors(int a){
    int n = 0;
    for(int i = 0; i <= ceil((double)a/2); i++){
        if(a % i == 0) n++;
    }
    return n;
}

void ex63(){
    cout << "Number \t -- \t Number of divisors" << endl;
    for(int i = 300; i <= 400; i++){
        cout << i << " \t -- \t " << calcNumDivisors(i) << endl;
    }
}
