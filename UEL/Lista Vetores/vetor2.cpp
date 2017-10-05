#include <iostream>
#include <iomanip>
#include <cmath>

#include "headers.hpp"
using namespace std;

#include <vector>

vector<int> bin;

void vet2(){
    int n;
    cout << "Insert number to be converted to binary: "; cin >> n;
    cout << n << " = ";
    int k;
    do{
        k = n % 2;
        bin.push_back(k);
        n = trunc(n/2);
    }while(n > 0);
    for(int i = bin.size(); i > 0; i--){
        cout << bin[i - 1];
    }
}
