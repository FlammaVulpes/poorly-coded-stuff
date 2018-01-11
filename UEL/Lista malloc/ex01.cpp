#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "header.hpp"

using namespace std;

void fetchVar(int *u, int *v){
    cin >> *u >> *v;
}

void ex01(){
    int *a, *b;
    a = (int*) malloc(sizeof(int));
    if(a == NULL){
        cout << "a = Null" << endl;
        exit(EXIT_FAILURE);
    }
    b = (int*) malloc(sizeof(int));
    if(b == NULL){
        cout << "b = Null" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Digite os valores de A e B: "; fetchVar(a, b);
    cout << "Soma dos dois valores (usando malloc): " << *a + *b << endl;

    free(a);
    free(b);
}
