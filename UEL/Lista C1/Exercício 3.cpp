#include <iostream>
#include <iomanip>
#include <cmath>
#include "headers.hpp"

double sum3 = 0;
int n3 = 1;

using namespace std;

void ex3(){
    cout << fixed;
    for(int i = 1; i <= 50; i++){
        double kek3 = pow(2, n3);
        sum3 += kek3/(51-n3);
        //cout << sum << endl;
        n3++;
    }
    cout << "Soma: " << sum3 << endl;
}
