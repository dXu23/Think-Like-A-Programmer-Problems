#include <iostream>
using namespace::std;

typedef struct charNode {
    char c;
    struct charNode *next;
} CHARNODE;

void print(CHARNODE * first) {
    CHARNODE * iternode = first;
    while (iternode != NULL) {
        cout << iternode->c;
    }
    cout << endl;
}

void append(CHARNODE * first, char c) {
    CHARNODE node = (CHARNODE *) malloc(sizeof(CHARNODE));
    CHARSTR * iterNode = first;
    CHARSTR * lastNode; 
    while (iterNode != NULL) {
        lastNode = iterNode;
        iterNode = iterNode->next;
    }
    lastNode->next = node;
}

void concatenate(CHARSTR * first, CHARSTR * second) {
    if (first == NULL) {
        first = second;
        return;
    }
    CHARSTR * iterNode = first;
    CHARSTR * lastNode; 
    while (iterNode != NULL) {
        lastNode = iterNode;
        iterNode = iterNode->next;
    }
    lastNode->next = second;
    return;
}



int main() {
    return 0;
}
