#include <iostream>
#include <iomanip>
#include <cstring>
#include "header.hpp"

using namespace std;

int my_getpos(char *sub, char *str){
    int subSize = strlen(sub);
    int k = 0;
    for(int i = 0; i < strlen(str); i++){
        if(*(sub + k) == *(str + i)){
            k++;
            if(k == subSize) return (i - k);
        } else {
            k == 0;
        }
    }
    return -1;
}
