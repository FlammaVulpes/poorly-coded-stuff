#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;


void listPushstart(int n, node **h){
    // Gerando uma célula
    node *aux = (node*) malloc(sizeof(node));

    // Atribuindo valor à ela
    aux->v = n;

    // Ligando ela ao elemento apontado pela "cabeça" da lista, ou seja, ao primeiro elemento
    aux->next = *h;

    // Tornar a "cabeça" da lista esse elemento que foi gerado na função
    *h = aux;
}
