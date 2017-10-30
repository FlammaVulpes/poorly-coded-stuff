#include <iostream>

#include "header.hpp"

using namespace std;

char texto[1000];
char palavra[20];

void str5(){
    cout << "Insira o texto: "; cin.getline(texto, 1000);
    cout << "Insira a palavra a ser buscada: "; cin >> palavra;
    cout << countSubstring(texto, palavra) << endl;
    fetchAndRemove(texto, palavra);
    cout << texto;
}

int countSubstring(char texto[1000], char palavra[20]){
    int k = 0;
    int i = 0, j;
    while(texto[i] != '\0'){
        j = 0;
        while(texto[i] == palavra[j]){
            i++; j++;
            if(palavra[j] == '\0') k++;
        }
        i++;
    }
    return k;
}

void fetchAndRemove(char texto[1000], char palavra[20]){
    int i = 0, j;
    while(texto[i] != '\0'){
        j = 0;
        while(texto[i] == palavra[j]){
            int r = i;
            i++; j++;
            if(palavra[j] == '\0'){
                // Eu estou trancado aqui nessa merda
                // Preciso dar um jeito de fazer isso funcionar
                // O que isso faz?
                // Supostamente, dá um shift left no seu char array sobrescrevendo toda a palavra
                // que você quer dentro do texto que você colocou.
                int tsize = sizeof(texto)/sizeof(texto[0]);
                int psize = sizeof(palavra)/sizeof(palavra[0]);
                for(int a = 0; a < tsize; a++){
                    texto[r + a] = texto[r + a + psize];
                }
                texto[r + psize + 1] = '\0';
            }
        }
        i++;
    }
}
