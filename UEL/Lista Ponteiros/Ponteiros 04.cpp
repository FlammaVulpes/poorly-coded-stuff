#include <iostream>
#include "headers.hpp"
using namespace std;

void sortArray(float *v, int n){
    for(int a = 0; a < n; a++){
        for(int b = a; b < n; b++){
            float t;
            // Selection sort ftw
            if(*(v + a) > *(v + b)){
                t = *(v + a);
                *(v + a) = *(v + b);
                *(v + b) = t;
            }
        }
    }
}

void ex4(){
    float A[20];

    cout << "A = ";
    for(int i = 0; i < 20; i++){
        cin >> *(A + i);
    }
    sortArray(A, 20);
    cout << "Array A ordenado = ";
    for(int i = 0; i < 20; i++){
        cout << *(A + i) <<  " ";
    }
}
