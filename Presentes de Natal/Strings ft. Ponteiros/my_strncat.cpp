#include <iostream>
#include <iomanip>
#include <cstring>
#include "header.hpp"

using namespace std;

void my_strncat(char *dest, char *source, int n){
    for(int i = 0; i < strlen(source); i++){
        *(dest + n + i + strlen(source)) = *(dest + n + i);
        *(dest + n + i) = *(source + i);
    }
}
