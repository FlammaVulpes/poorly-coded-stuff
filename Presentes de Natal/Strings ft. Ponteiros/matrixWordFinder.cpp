#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "header.hpp"

using namespace std;
// Originalmente my_hasWordInACharMatrixPleaseKillMeNowICannotHandleThisAnymore.cpp, porque índices são uma desgraça

bool hasInLineOrColumn(char *word, char *arr){
    char line[30];
    char column[30];
    for(int i = 0; i < 30; i++){
        // Para cada linha e coluna, usar my_getpos() para determinar se existe ou não
        for(int j = 0; j < 30; j++){
            line[j] = arr[(30 * i) + j];
            column[j] = arr[i + (30 * j)];
        }
        if(my_getpos(word, line) != -1 || my_getpos(word, column) != -1){
            return true;
        }
    }
    return false;
}

bool hasInDiagonal(char *word, char *arr){
    char diagonalString[30];
    for(int i = 0; i < 30; i++){
        // [0, 29] -> [29]
        // [0, 28], [1, 29] -> [28], [59]
        // [0, 27], [1, 28], [2, 29] -> [27], [58], [89]
        // ...
        // [0, x], [1, x-1], ..., [n, x-n] -> [(x - n) + 31n]
        // BUGADA MENTAL INCRÍVEL
        // PROVAVELMENTE VOU ESQUECER DE ARRUMAR ISSO AQUI ANTES DE ENVIAR
        for(int j = (29 - i); j < 30; j++){
            diagonalString[29 - i] = arr[i + (31 * j)];
        }
        if(my_getpos(word, diagonalString) != -1){
            return true;
        }
    }
    return false;
}

bool hasWord(char *word){
    char field[900];

    // Leitura da matriz de palavras
    ifstream fin;
    fin.open("wordField.txt");
    for(int i = 0; i < 30; i++){
        if(i != 0) fin.ignore();
        char line[31];
        fin.getline(line, 31);
        for(int j = 0; j < 30; j++){
            field[(30 * i) + j] = line[j];
        }
    }
    if(hasInDiagonal(word, field) || hasInLineOrColumn(word, field)){
        return true;
    }
    return false;
}
