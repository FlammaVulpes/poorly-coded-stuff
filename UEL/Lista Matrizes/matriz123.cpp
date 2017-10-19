#include <iostream>
#include <iomanip>
#include <cmath>

#include "headerMatrizes.hpp"
using namespace std;

void mat1(){
    int matrix[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << "Insert [" << i+1 << "," << j+1 << "]: "; cin >> matrix[i][j];
        }
    }
    // Printa a diagonal principal
    for(int i = 0; i < 10; i++){
        cout << "Elemento [" << i+1 << "," << i+1 << "]: " << matrix[i][i];
    }
}

void mat2(){
    int matrix[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << "Insert [" << i+1 << "," << j+1 << "]: "; cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // Elementos cuja posi��o � inferior � diagonal principal
            if(j < i) cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void mat3(){
    int matrix[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << "Insert [" << i+1 << "," << j+1 << "]: "; cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // Elementos cuja posi��o � superior � diagonal principal
            if(j > i) cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
