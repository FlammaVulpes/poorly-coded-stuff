#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "header.hpp"

using namespace std;

void fetchMatrix(int **q, int height, int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> (q[i] + j);
        }
        cout << "\n\t";
    }
}

void ex03(){
    int **m; // Bidimensional - matrizes são implementadas como vetores de vetores
    int h, w; // Height (linhas), Width (colunas)
    cout << "Entre com a quantidade de linhas e colunas da matriz: "; cin >> h >> w;
    m = (int) malloc(h * sizeof(int*));
    for(int i = 0; i < h; ++i){
        m[i] = (int) malloc(w * sizeof(int));
    }
    cout << "Entre com a matriz:\n\t ";
    fetchMatrix(m, h, w);
}
