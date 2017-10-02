#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp";
using namespace std;

int index = 0;

void ex61(){
    for(int i = 1000; i <= 9999; i++){
        int a = trunc(i/100);
        int b = i - (100 * a);
        if(pow((double) a, 2) + pow((double) b, 2) == i){
            if(index <= 6){
                cout << "\n";
                index = 0;
            }
            cout << i << "\t";
            index++;
        }
    }
}
