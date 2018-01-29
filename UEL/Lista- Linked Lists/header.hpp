struct Node{
    int v;
    Node *next;
};
typedef Node node;

void listPushback(int, node**);
void listPushstart(int, node**);
void insertInMiddle(int, int, node*);

void popFront(node**);
void popBack(node**);
void popByIndex(int, node**);

void printContents(node*);
int getNodeAmount(node*);
