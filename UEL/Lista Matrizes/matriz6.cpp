#include <iostream>
#include <iomanip>
#include <cmath>

#include "headerMatrizes.hpp"
using namespace std;

void mat6(){
    int A[10][20];
    int B[20][10];
    // Leitura de A
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            cout << "Insira A[" << i+1 << "," << j+1 << "]: "; cin >> A[i][j];
        }
    }
    // Escrita de A
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    // Transposição de A em B
    // Aproveitar e escrever em um único for. Eficiência, eles disseram.
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            B[j][i] = A[i][j];
            cout << B[j][i] << " ";
        }
        cout << endl;
    }
}
