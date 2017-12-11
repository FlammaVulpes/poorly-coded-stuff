#include <iostream>
#include "headers.hpp"

using namespace std;

void ex1(){
    double v[10];
    for(int i = 0; i < 10; i++){
        double c;
        cin >> c;
        *(v + i) = c;
    }
    for(int i = 0; i < 10; i++){
        cout << *(v + i) << endl;
    }
}
