#include <iostream>
#include <iomanip>
#include <cmath>

#include "headerMatrizes.hpp"
using namespace std;

void mat4(){
    int matrix[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            matrix[i][j] = 0; // Setando tudo para zero inicialmente
        }
    }
    for(int bound = 0; bound < 3; bound++){
        for(int i = 0 + bound; i < 6 - bound; i++){
            for(int j = 0 + bound; j < 6 - bound; j++){
                matrix[i][j] += 1;
            }
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
