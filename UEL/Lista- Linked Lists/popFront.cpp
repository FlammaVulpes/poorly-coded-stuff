#include <iostream>
#include <cstdlib>

#include "header.hpp"
using namespace std;

void popFront(node **h){
    node *secNode = NULL;

    secNode = (*h)->next;
    free(*h);
    *h = secNode;
}


