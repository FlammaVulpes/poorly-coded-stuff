#include <iostream>
#include <fstream>
#include <iomanip>

#include "headers.hpp"
using namespace std;

void ex2(){
    int k = 0;
    ifstream fin;
    char arqName[40];
    cout << "Insira o nome do arquivo: "; cin >> arqName;
    fin.open(arqName);
    while(!fin.eof()){
        char input[40];
        if(fin >> input) k++;
    }
    cout << k;
    fin.close();
}

