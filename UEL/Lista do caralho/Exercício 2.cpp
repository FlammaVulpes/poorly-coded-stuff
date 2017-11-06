#include <iostream>
#include <fstream>

#include "header.hpp"
using namespace std;

int sudoku[9][9];

void fetchSudoku(){
    ifstream fin;
    fin.open("sudoku.txt");
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            //cin >> sudoku[i][j];
            fin >> sudoku[i][j];
        }
    }
}

int checkLine(int line){
    int arr[9];
    for(int i = 0; i < 9; i++){
        arr[i] = sudoku[line][i];
    }
    sudSort(arr);
    for(int i = 0; i < 9; i++){
        if(arr[i] != (i + 1)) return 0;
    }
    return 1;
}

int checkColumn(int column){
    int arr[9];
    for(int i = 0; i < 9; i++){
        arr[i] = sudoku[i][column];
    }
    sudSort(arr);
    for(int i = 0; i < 9; i++){
        if(arr[i] != (i + 1)) return 0;
    }
    return 1;
}

int checkSubsquare(int x, int z){
    int arr[9];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr[3*i + j] = sudoku[(3*x) + i][(3*z) + j];
        }
    }
    sudSort(arr);
    for(int i = 0; i < 9; i++){
        if(arr[i] != (i+1)) return 0;
    }
    return 1;
}

void ex2(){
    int notSudoku = 0;
    fetchSudoku();
    for(int i = 0; i < 9; i++){
        if(checkLine(i) == 0 || checkColumn(i) == 0){
            notSudoku = 1;
            break;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(checkSubsquare(i, j) == 0){
                notSudoku = 1;
                break;
            }
        }
    }
    if(notSudoku) cout << "NAO" << endl;
    else cout << "SIM" << endl;
}
