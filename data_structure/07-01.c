#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int elem;
    struct Node *next;
} Node;

typedef struct {
    Node *H;
} List;

List *makeList() {
    List *L = (List *) malloc(sizeof(List));

    L->H = NULL;

    return (L);
}

Node *makeNode(int e) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->elem = e;
    node->next = NULL;

    return (node);
}

void append(List *L, int e) {
    Node *node = makeNode(e);

    Node *p = L->H;
    if (!p) {
        L->H = node;
    } else {
        while (p->next)
            p = p->next;
        p->next = node;
    }
}

int subset(List *A, List *B) {
    Node *p = A->H;
    Node *q = B->H;

    while (p) {
        if (!q || p->elem < q->elem)
            return (p->elem);
        
        if (p->elem == q->elem)
            p = p->next;
        q = q->next;
    }
    return (0);
}

int main() {
    List *A = makeList();
    List *B = makeList();

    int n, e;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        append(A, e);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        append(B, e);
    }

    printf("%d", subset(A, B));

    return (0);
}