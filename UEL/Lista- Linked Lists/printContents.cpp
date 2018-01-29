#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

void printContents(node *h){
    //node *aux = (node*) malloc(sizeof(node*));
    node *aux = h;

    while(aux != NULL){
        cout << aux->v << endl;
        aux = aux->next;
    }
}
