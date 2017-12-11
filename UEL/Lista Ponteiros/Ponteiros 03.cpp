#include <iostream>
#include "headers.hpp"
using namespace std;

void invertArray(char *a){
    char t;
    for(int i = 0; i < 5; i++){
        t = *(a + i);
        *(a + i) = *(a + (9 - i));
        *(a + (9 - i)) = t;
    }
}

void ex3(){
    char A[10];
    cout << "A = ";
    for(int i = 0; i < 10; i++){
        cin >> *(A + i);
    }
    invertArray(A);
    cout << "Inversa de A = ";
    for(int i = 0; i < 10; i++){
        cout << *(A + i) << " ";
    }
}
