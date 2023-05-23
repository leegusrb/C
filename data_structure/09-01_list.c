#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *S) {
    S->top = NULL;
}

Node *getNode() {
    return ((Node *) malloc(sizeof(Node)));
}

void push(Stack *S, char e) {
    Node *p = getNode();
    p->elem = e;
    p->next = S->top;
    S->top = p;
}

char pop(Stack *S) {
    char e = S->top->elem;
    Node *p = S->top;
}