#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

int n10 = 1;
double e;
long long x10;
long long a10 = x10;

int factorial(int c){
    if(n10 == 0 || n10 == 1){
        return 1;
    } else {
        int fac = 1;
        do{
            fac *= c;
            c--;
        }while(c >= 1);
        return fac;
    }
}

double calcEx(long long c){
    double k = pow(x10, c);
    e += k/factorial(n10);
    n10++;
    return e;
}

void ex10(){
    cout << fixed << setprecision(10);
    cout << "Insert the value of x: ";
    cin >> x10; cout << endl;
    e = x10/factorial(0);
    while(abs(exp(x10) - e) > 0.0001){
        cout << "Iteration " << n10 << " -- e = " << calcEx(a10) << endl;
    }
}
