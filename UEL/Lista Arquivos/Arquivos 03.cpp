#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "headers.hpp"
using namespace std;

struct Dados{
    char nome[40];
    int idade;
};

void searchByName(char nome[40], char fileName[40]){
    ifstream fin;
    fin.open(fileName);
    for(int i = 0; i < 5; i++){
        char n[40];
        if(i != 0) fin.ignore();
        fin.getline(n, 40);
        int idade;
        fin >> idade;
        if(strcmp(nome, n) == 0){
            cout << "Idade de " << nome << ": " << idade << endl;
            return;
        }
    }
    cout << "Nome nao encontrado!" << endl;
    return;
}

void ex5(){
    ifstream fin; ofstream fout;
    cout << "Inserindo registros no arquivo de saida... " << endl;
    char inName[40] = "registrosIn";
    char outName[40] = "registrosOut";
    fin.open(inName); fout.open(outName);
    Dados dados[5];
    for(int i = 0; i < 5; i++){
        if(i != 0) fin.ignore();
        fin.getline(dados[i].nome, 40);
        fin >> dados[i].idade;
    }
    for(int i = 0; i < 5; i++){
        fout << dados[i].nome << endl;
        fout << dados[i].idade << endl;
    }
    cout << "Insercao concluida!" << endl;
    cout << "Digite um nome para procurar: ";
    char toFind[40];
    cin.getline(toFind, 40);
    searchByName(toFind, inName);
}
