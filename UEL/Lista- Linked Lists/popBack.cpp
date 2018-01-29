#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

void popBack(node **h){
    node *tail, *beforeTail;

    beforeTail = *h;

    // Pegando o último e penúltimo elementos
    while(beforeTail->next->next != NULL){
        beforeTail = beforeTail->next;
    }
    tail = beforeTail->next;
    beforeTail->next = NULL;
    free(tail);
}



