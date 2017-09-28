#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

int gcd(int a, int b){
    if(a < b){ return gcd(b, a); }
    if(a % b == 0){ return b; } else { return gcd(b, a % b); }
}

int input[3];

void ex11(){
    while(1){
        for(int i = 0; i < 3; i++){
            cout << "Insert number " << i + 1 << ": ";
            cin >> input[i];
        }
        if(input[0] == 0 && input[1] == 0 && input[2] == 0) { cout << "As three 0s have been input, the program is now terminated." << endl; break; }
        int result = gcd(gcd(input[0], input[1]), input[2]);
        cout << "The Greatest Common Divisor (GCD) between " << input[0] << ", " << input[1] << " and " << input[2] << " is " << result << "." << endl;
    }
}
