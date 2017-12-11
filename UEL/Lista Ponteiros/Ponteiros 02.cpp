#include <iostream>
#include "headers.hpp"

using namespace std;

void arrayConcat(float *pa, float *pb, float *v){
    int j = 0;
    for(int i = 0; i < 10; i++){
        *(v + j) = *(pa + i);
        j++;
        *(v + j) = *(pb + i);
        j++;
    }
}

void ex2(){
    float A[5], B[5];
    cout << "A = ";
    for(int i = 0; i < 5; i++){
        cin >> *(A + i);
    }
    cout << endl;
    cout << "B = ";
    for(int i = 0; i < 5; i++){
        cin >> *(B + i);
    }
    float C[10];
    arrayConcat(A, B, C);
    cout << "C = ";
    for(int i = 0; i < 10; i++){
        cout << *(C + i) << " ";
    }
}
