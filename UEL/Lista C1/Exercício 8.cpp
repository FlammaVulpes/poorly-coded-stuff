#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

double input, sum = 0;

void ex8(){
    cout << fixed << setprecision(7);
    cout << "Insert a number: ";
    cin >> input;
    for(int i = 1; i <= 25; i++){
        long long k = pow(input, 26-i);
        if(i % 2 == 1) sum+= (double) k/i;
        else sum-= (double) k/i;
        //cout << "Iteration #" << i << " -- Sum = " << sum << endl;
    }
    cout << "Sum: " << sum << endl;
}
