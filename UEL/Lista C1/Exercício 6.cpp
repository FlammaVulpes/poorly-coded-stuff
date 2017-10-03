#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

void ex6(){
    cout << fixed << setprecision(12);
    double pi = 3.141592;
    double ourPi = 4, n = 3;
    int i = 0;
    while(abs(pi - ourPi) > 0.0001){
        i++;
        cout << "Iteration " << i << ", pi = " << ourPi << endl;
        if(i % 2 == 1) ourPi -= 4/n;
        else ourPi += 4/n;
        n+=2;
    }
    cout << "After " << i << " iterations, the difference between real pi (" << pi << ") and our pi (" << ourPi << ") was lower than 0.0001." << endl;
}
