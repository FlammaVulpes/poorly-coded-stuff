#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "header.hpp"

using namespace std;

void fetchArrays(char *q, char *w, int s1, int s2){
    cout << "Entre com os elementos de A: ";
    for(int i = 0; i < s1; i++){
        cin >> q + i;
    }
    cout << "Entre com os elementos de B: ";
    for(int i = 0; i < s2; i++){
        cin >> w + i;
    }
}

void writeArrays(char *q, char *w, int s1, int s2){
    cout << "\tVetor A: ";
    for(unsigned int i = 0; i < s1; i++){
        cout << *(q + i) << " ";
    }
    cout << endl;
    cout << "\tVetor B: ";
    for(unsigned int i = 0; i < s2; i++){
        cout << *(w + i) << " ";
    }
}

void intercalateArrays(char *q, char *w, int s1, int s2){
    cout << "\nIntercalando vetores A e B: \n\t";
    for(unsigned int i = 0; i < (s1 + s2); i++){
        if(i < s1){
            cout << *(q + i);
        }
        if(i < s2){
            cout << *(w + i);
        }
    }
}

char *concatenateArrays(char *q, char *w, int s1, int s2){
    char *c;
    c = (char*) malloc(sizeof(char) * (s1 + s2));
    for(int i = 0; i < s1; i++){
        *(c + i) = *(q + i);
    }
    for(int i = 0; i < s2; i++){
        *(c + s1 + i) = *(w + i);
    }
    return c;
}

void deleteArrays(char *q, char *w){
    free(q); free(w);
    cout << "\nMemoria liberada" << endl;
}

void ex02(){
    int sa, sb;
    cout << "Insira o tamanho dos vetores A e B: "; cin >> sa >> sb;
    char *a, *b;

    a = (char*) malloc(sizeof(char) * sa);
    if(a == NULL){
        cout << "A = NULL" << endl;
        exit(EXIT_FAILURE);
    }
    b = (char*) malloc(sizeof(char) * sb);
    if(b == NULL){
        cout << "B = NULL" << endl;
        exit(EXIT_FAILURE);
    }

    fetchArrays(a, b, sa, sb);
    writeArrays(a, b, sa, sb);
    intercalateArrays(a, b, sa, sb);
    char *c = concatenateArrays(a, b, sa, sb);
    cout << "\nTeste de concatenacao: \n\t" << c;
    deleteArrays(a, b);
}
