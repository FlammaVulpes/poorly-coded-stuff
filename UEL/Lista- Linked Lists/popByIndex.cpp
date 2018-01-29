#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

void popByIndex(int index, node **h){
    node *aux = *h;
    node *tmp = NULL;

    if(index == 0){
        popFront(&(*h));
        return;
    }

    for(int i = 1; i < index; i++){
        if(aux->next == NULL){
            return;
        }
        aux = aux->next;
    }

    tmp = aux->next;
    aux->next = tmp->next;
    free(tmp);
}




