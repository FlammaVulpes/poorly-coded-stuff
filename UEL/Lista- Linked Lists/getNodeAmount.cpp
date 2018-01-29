#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

int getNodeAmount(node *h){
    node *aux = h;
    int k = 0;

    while(aux != NULL){
        k++;
        aux = aux->next;
    }
    return k;
}

