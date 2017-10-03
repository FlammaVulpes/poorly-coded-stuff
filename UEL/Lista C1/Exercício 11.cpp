#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;
int numberInput[3];

int gcd(int a, int b){
    if(a < b) return gcd(b, a);
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

void ex11(){
    while(1){
        for(int i = 0; i < 3; i++){
            cout << "Insert number " << i+1 << ": ";
            cin >> numberInput[i];
        }
        if(numberInput[0] == 0 && numberInput[1] == 0 && numberInput[2] == 0) break;
        int q = gcd(gcd(numberInput[0], numberInput[1]), numberInput[2]);
        cout << "The Greatest Common Divisor between " << numberInput[0] << ", " << numberInput[1] << " and " << numberInput[2] << " is: " << q << endl;
    }
    cout << "As three 0s have been input, the program is now terminated." << endl;
}
