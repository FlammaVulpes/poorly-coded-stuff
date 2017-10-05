#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

int datVector[20];

void readVector(){
    for(int i = 0; i < 20; i++){
        cout << "Insert element number #" << i + 1 << ": ";
        cin >> datVector[i];
    }
}

int findBiggest(){
    int bigIndex;
    for(int i = 0; i < 20; i++){
        if(i == 0){
            bigIndex = i;
        } else {
            if(datVector[i] > datVector[bigIndex]){
                bigIndex = i;
            }
        }
    }
    return bigIndex;
}

void vet1(){
    readVector();
    findBiggest();
    cout << "The biggest number entered was: " << datVector[findBiggest()] << endl;
}
