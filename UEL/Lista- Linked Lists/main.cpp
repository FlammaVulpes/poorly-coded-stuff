#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;


int main(){
    node *head;

    // Inicializando a lista
    head = NULL;

/*
    // Gerando a primeira célula
    node *aux = (node*) malloc(sizeof(node*));

    // Apontando a primeira célula para o nada, ou seja, é o fim dela
    aux->next = NULL;

    // Faz a cabeça apontar para esse node gerado
    head = aux; */

    //listPushstart(10, &head);

    listPushback(3, &head);
    listPushback(5, &head);
    listPushback(400, &head);

    insertInMiddle(2, 40, head);
    listPushstart(-2, &head);
    insertInMiddle(1, -1, head);

    printContents(head);

    cout << "----" << endl;

    popFront(&head);
    popBack(&head);
    popByIndex(1, &head);

    printContents(head);

    return 0;
}
