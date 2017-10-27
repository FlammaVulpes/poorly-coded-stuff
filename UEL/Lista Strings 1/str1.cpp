#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "header.hpp"
using namespace std;

char frase[1000];
char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

void checkVogal(int i){
    for(int a = 0; a < 5; a++){
        if(frase[i] == vogais[a]) cout << frase[i];
    }
}

void str1(){
    cout << "Insira a frase: ";
    cin.getline(frase, 1000);
    cout << "Vogais:\n\t";
    for(int i = 0; i < sizeof(frase)/sizeof(frase[0]); i++){
        checkVogal(i);
    }
    cout << "\n";
}

