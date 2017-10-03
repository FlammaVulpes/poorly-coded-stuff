#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

long long fatorial(int num){
    if(num == 1 || num == 0) return 1;
    else{
        long long a = 1;
        do{
            a *= num;
            num--;
        }while(num > 1);
        return a;
    }
}

void ex9(){
    double sum = 0;
    cout << fixed << setprecision(10);
    for(int i = 0; i < 20; i++){
        sum += (double) (100 - i)/fatorial(i);
        //cout << "Iteration #" << i + 1 << " -- Sum = " << sum << endl;
    }
    cout << "Sum = " << sum << endl;
}
