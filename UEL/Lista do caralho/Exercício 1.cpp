#include <iostream>
#include <cstring>

#include "header.hpp"

using namespace std;

struct palavra{
    char p[24];
    int q;
};

palavra lista[1000];

void ex1(){
    int n = 0;
    // Inicializando
    for(int i = 0; i < 1000; i++){ lista[i].q = 0; }
    while(1){
        int i;
        char word[24];
        char vazio[6] = "vazio";
        cout << "Insira uma palavra: "; cin >> word;
        if(strcmp(word, vazio) == 0) break;
        for(i = 0; i < 1000; i++){
            if(lista[i].q == 0){
                strcpy(lista[i].p, word);
                lista[i].q++;
                n++;
                break;
            } else if(strcmp(lista[i].p, word) == 0){
                lista[i].q++;
                break;
            }
        }
    }
    cout << "\nEntrada terminada, imprimindo resultados: " << endl;
    for(int i = 0; i < n; i++){
        cout << "\t" << lista[i].p << " (" << lista[i].q << ")" << endl;
    }
}
