#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"

using namespace std;

void ex7(){
    cout << fixed << setprecision(10);
    double pi, s = 0;
    for(int i = 0; i < 51; i++){
        double den = pow(2*i + 1, 3);
        if(i % 2 == 0) s += 1/den; else  s -= 1/den;
        //cout << "Iteration " << i+1 << " -- s = " << s << endl;
    }
    pi = cbrt(32*s);
    cout << "pi = " << pi << endl;
}
