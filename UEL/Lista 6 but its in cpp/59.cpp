#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp";
using namespace std;

int n;
double intEval = 0;

double intFunc(double k){
    double den = 1 + pow(k, 2);
    return 1 / den;
}

void ex59(){
    cout << "In how many parts should I divide this interval? "; cin >> n;
    cout << fixed << setprecision(10);
    for(int i = 0; i < n; i++){
        intEval += ((intFunc((double) i/n) + intFunc((double) (i+1)/n))/2) * ((double) 1/n);
        cout << "Integral value (iteration " << i + 1 << "/" << n << "): " << intEval << endl;
    }
    cout << "The integral of dx/(1+x^2), from 0 to 1, is equal to " << intEval << ", which is pi/4." << endl;
    cout << "In other words, pi = " << 4 * intEval << "." << endl;
}

