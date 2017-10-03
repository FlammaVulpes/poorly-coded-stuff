#include <iostream>
#include <iomanip>
#include <cmath>
#include "headers.hpp"

double sum4 = 0;
int n4 = 1;

using namespace std;

void ex4(){
    cout << fixed << setprecision(5);
    do{
        sum4 += (float) ((38 - n4)*(39 - n4))/n4;
        n4++;
        //cout << "Iteração " << n4-1 << " --- " << sum4 << endl;
    }while(n4<=37);
    cout << "Soma: " << sum4 << endl;
}
