#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

#include <vector>

vector <char>hexd;
vector <int>holder;

char toHex(int n){
    switch(n){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
    }
    return '0';
}


void vet3(){
    int a;
    while(1){
        cout << "Insert a number to be converted: "; cin >> a;
        if(a == 0){ cout << "\nProgram terminated!\n"; break; }
        int k;
        cout << a << " = ";
        do{
            k = a % 16;
            //cout << k << " ";
            holder.push_back(k);
            a = trunc(a/16);
        }while(a > 0);
        for(int i = holder.size(); i > 0; i--){
            cout << toHex(holder[i - 1]);
            holder.pop_back();
        }
        cout << "\n";
    }
}
