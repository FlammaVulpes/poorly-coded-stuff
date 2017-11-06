#include <iostream>

#include "header.hpp"

using namespace std;

int bloco[10000][10000];
int data[10000];

void ex3(){
    int a, c;
    while(1){
        cout << "Insira a altura do bloco: ";
        cin >> a;
        cout << "Insira o comprimento do bloco: ";
        cin >> c;
        if(a == 0 && c == 0) break;
        cout << "Insira as alturas de cada comprimento: ";
        for(int i = 0; i < c; i++){
            cin >> data[i];
        }
        // Construir a matriz
        for(int i = 0; i < a; i++){
            for(int j = 0; j <= c; j++){
                if(data[j] >= 0){
                    bloco[a - i][j] = 1;
                    data[j]--;
                } else {
                    bloco[a - i][j] = 0;
                }
            }
        }

        // Percorrer a matriz;
        int n = 0;
        for(int i = 0; i < a; i++){
            int j = 1;
            while(j < c){
                int soma = 0;
                if((bloco[i][j] == 1 && bloco[i][j-1] == 0)){
                    n++;
                }
                soma += bloco[i][j];
                j++;
                if(j == c && soma == 0) n++;
            }
        }
    cout << n << "\n" << endl;
    }
}
