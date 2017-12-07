#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

const int matrixSize = 2; // Controla o tamanho máximo da matriz

void fetchLine(vector< vector<double> > &matrix, vector<double> &line, int l){
    cout << "\tInserir elementos da linha " << l << " da matriz: ";
    for(int i = 0; i < 2 * matrixSize; i++){
        if(i >= matrixSize){
            if(i == (matrixSize + l)){
                line.push_back(1);
            } else {
                line.push_back(0);
            }
        } else {
            double input;
            cin >> input;
            line.push_back(input);
        }
    }
    matrix.push_back(line);
    for(int i = 0; i < 2 * matrixSize; i++){
        line.pop_back();
    }
}

void fetchMatrix(vector< vector<double> > &matrix, vector<double> &line){
    for(int i = 0; i < matrixSize; i++){
        fetchLine(matrix, line, i);
    }
}

// Hora de escalonar as matrizes e ver no que vai dar :)

void scaleMatrix(vector< vector<double> > &matrix, vector<double> &line, int l){
    //Escalonar na parte acima da linha l e, depois, abaixo da linha l
    
    double factor = *(matrix)[l][l];
    for(int i = 0; i < matrixSize; i++){
        if(i == l) continue;
        for(int k = 0; k < 2 * matrixSize; k++){
            *(matrix)[l][k] *= factor;
        }
    }
}

void scaleLine(vector< vector<double> > &matrix, vector<double> &line, int l){
    for(int i = 0; i < 2 * matrixSize; i++){
        line.insert(i, line.at(i)/line.at(l));
    }
    scaleMatrix(matrix, line, l);
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
    fetchMatrix(matrix, line);
    for(int i = 0; i < matrixSize; i++){
        scaleLine(matrix, line, i);
    }
    printMatrix(matrix);
    return 0;
}

// Tá dando erro, ou alterar isso depois ou resolver usar apenas um vetor unidimensional
