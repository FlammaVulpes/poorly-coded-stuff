#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;


void listPushstart(int n, node **h){
    // Gerando uma c�lula
    node *aux = (node*) malloc(sizeof(node));

    // Atribuindo valor � ela
    aux->v = n;

    // Ligando ela ao elemento apontado pela "cabe�a" da lista, ou seja, ao primeiro elemento
    aux->next = *h;

    // Tornar a "cabe�a" da lista esse elemento que foi gerado na fun��o
    *h = aux;
}
