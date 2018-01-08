#include <iostream>
#include <iomanip>
#include <cstring>
#include "header.hpp"

using namespace std;

void my_strcpy(char *dest, char *source){
    // Que, na verdade, é um strcat disfarçado de strcpy?
    int finalPos = strlen(dest);
    for(int i = 0; i < strlen(source); i++){
        *(dest + finalPos + i) = *(source + i);
    }
}
