#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

void vet6(){
    int i, a;
    while(1){
        cout << "Insert an even number: ";
        cin >> a;
        if(a < 0){ cout << "Program terminated."; break; }
        i = 2;
        while(1){
            if(checkPrime(a - i) && checkPrime(i)){ break; }
            i++;
        }
        cout << a << " = " << a - i << " + " << i << endl;
    }
}
