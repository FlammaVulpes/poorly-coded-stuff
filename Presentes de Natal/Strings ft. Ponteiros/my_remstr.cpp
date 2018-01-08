#include <iostream>
#include <iomanip>
#include <cstring>
#include "header.hpp"

using namespace std;

void my_remstr(char *frase, char *palavra){
    int pSize = strlen(palavra);
    int k = 0;
    bool found = false;
    for(int i = 0; i < strlen(frase); i++){
        k == 0;
        while(*(palavra + k) == *(frase + i + k)){
            k++;
            if(k == pSize) found = true;
        }
        if(found){
            for(int a = i; a < strlen(frase); a++){
                *(frase + a) = *(frase + a + k);
            }
            i = strlen(frase);
        }
    }
}
