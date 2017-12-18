#include <iostream>
#include <fstream>
#include <iomanip>

#include "headers.hpp"
using namespace std;

void ex1(){
    ifstream fin;
    char arqName[50];
    cout << "Entre com o nome do arquivo: "; cin >> arqName;
    fin.open(arqName);
    while(!fin.eof()){
        char input[30];
        if(fin >> input) cout << input << " ";
    }
    fin.close();
}
