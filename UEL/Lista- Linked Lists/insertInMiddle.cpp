#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

void insertInMiddle(int n, int v, node *h){
    node *aux = h;
    node *check = h;
    node *p;


    node *newNode = (node*) malloc(sizeof(node*));
    newNode->v = v;

    if(getNodeAmount(check) < n){
        cout << "A lista nao possui elementos suficientes!" << endl;
    } else {
        for(int i = 0; i < n; i++){
            p = aux;
            aux = aux->next;
        }
        p->next = newNode;
        newNode->next = aux;
    }
}

