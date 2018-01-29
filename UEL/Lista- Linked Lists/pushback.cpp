#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

// Adicionar ao fim de uma lista
void listPushback(int n, node **h){
    node *aux = (node*) malloc(sizeof(node*));
    aux->next = NULL;
    aux->v = n;
    if(*h == NULL){
        *h = aux;
    } else {
        node *t = *h; // t = tail
        // Encontrando o elemento final da lista
        while(t->next != NULL){
            t = t->next;
        }
        // Colocando ela no final da lista
        t->next = aux;
    }
}
