#include <iostream>
#include <cstring>

#include "header.hpp"

using namespace std;

char texto[1000];
char palavra[20];

void str5(){
    int escolha;
    while(1){
        cout << "Menu: " << endl;
        cout << "\t1) Contar numero de ocorrencias\n\t2) Retirar palavras da frase\n\t3) Sair" << endl;
        cout << "Insira a sua escolha: ";
        cin >> escolha;
        cin.ignore();
        if(escolha == 3){ cout << "Programa terminado!" << endl; break; }
        cout << "Insira o texto: "; cin.getline(texto, 1000);
        cout << "Insira a palavra a ser buscada: "; cin >> palavra;
        if(escolha == 1) cout << countSubstring(texto, palavra) << " ocorrencias de \"" << palavra << "\" no texto." << endl;
        if(escolha == 2){ fetchAndRemove(texto, palavra); cout << texto << endl; }
    }
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
    int i = 0, j, r;
    int psize, tsize;
    while(texto[i] != '\0'){
        j = 0;
        if(texto[i] == palavra[j]) r = i;
        while(texto[i] == palavra[j]){
            i++; j++;
            if(palavra[j] == '\0'){
                // Aparentemente, eu consegui resolver essa merda.
                tsize = strlen(texto);
                psize = strlen(palavra);
                for(int a = 0; a < tsize; a++){
                    texto[r + a - 1] = texto[r + a + psize];
                }
                texto[tsize - psize] = '\0';
            }
        }
        i++;
    }
}
