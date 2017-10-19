#include <iostream>
#include <iomanip>
#include <cmath>

#include "headerMatrizes.hpp"
using namespace std;

void mat5(){
    int matrix[100][200];
    int soma = 0;
    int n;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 200; j++){
            cout << "Insira m[" << i+1 << "," << j+1 << "]: "; cin >> matrix[i][j];
        }
    }
    cout << "Insira o numero da linha: "; cin >> n;
    for(int j = 0; j < 200; j++){
        soma += matrix[n][j];
    }
    cout << "Soma dos elementos da linha " << n+1 << " : " << soma << endl;
}
