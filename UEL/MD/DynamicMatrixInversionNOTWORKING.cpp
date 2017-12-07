#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

const int matrixSize = 2; // Controla o tamanho máximo da matriz

void fetchMatrix(vector<double> &matrix){
    cout << "\tInserir elementos das linhas da matriz " << matrixSize << "x" << matrixSize << ": \n";
    for(int k = 0; k < matrixSize; k++){
        for(int i = 0; i < 2 * matrixSize; i++){
            if(i >= matrixSize){
                if(i == (matrixSize + k)){
                    matrix.push_back(1);
                } else {
                    matrix.push_back(0);
                }
            } else {
                double input;
                cin >> input;
                matrix.push_back(input);
            }
        }
        cout << endl;
    }
}

// Hora de escalonar as matrizes e ver no que vai dar :)

void scaleMatrix(vector<double> &matrix){
    //Escalonar a porra toda
    for(int i = 0; i < matrixSize; i++){
        double factor;
        // Escalonar cada linha -> deixar o elemento (l, l) = 1
        for(int k = 0; k < 2 * matrixSize; k++){
            if(k == 0){
                factor = matrix.at(matrixSize * i + k);
            } else {
                matrix.insert(matrix.begin() + (matrixSize * i) + k, matrix.at(matrixSize * i + k)/factor);
            }
        }
        // Por fim, escalonar toda a matriz
        // Escalonar acima da linha l e, depois, abaixo da linha l
        for(int k = 0; k < matrixSize; k++){
            if(i == k) continue;
            factor = matrix.at(matrixSize * i + k);
            // Para cada elemento da linha
            for(int j = 0; j < 2 * matrixSize; j++){
                matrix.insert(matrix.begin() + (matrixSize * i) + k, matrix.at(matrixSize * i + k) - matrix.at);
                //
                //
                //
                //
                //
                //
                //
                //
            }
        }
    }
}

void printMatrix(vector< vector<double> > &matrix){
    for(int a = 0; a < matrixSize; a++){
        for(int b = 0; a < 2 * matrixSize; b++){
            cout << *(matrix)[a][b] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector< vector<double> > matrix; // Criando um vetor dinâmico (1D) de vetores dinâmicos (2D) -> Matriz dinâmica
    vector<double> line; // Adicionar cada linha individualmente
    fetchMatrix(matrix);
    for(int i = 0; i < matrixSize; i++){
        scaleLine(matrix, line, i);
    }
    printMatrix(matrix);
    return 0;
}

// Fazer no papel e ajustar as funções e as variáveis.
