#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int elem;
    struct Node *next;
} Node;

typedef struct {
    Node *H;
} List;

void init(List *L);

void input(List *L, int n);

void add(List *L, int e);

int subset(List *A, List *B);

int main() {
    List *A = (List *) malloc(sizeof(List));
    List *B = (List *) malloc(sizeof(List));
    init(A);
    init(B);

    int n;

    scanf("%d", &n);
    input(A, n);

    scanf("%d", &n);
    input(B, n);

    printf("%d\n", subset(A, B));

    return 0;
}

void init(List *L) {
    L->H = NULL;
}

void input(List *L, int n) {
    for (int i = 0; i < n; i++) {
        int e;
        scanf("%d", &e);
        add(L, e);
    }
}

void add(List *L, int e) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->elem = e;
    node->next = NULL;

    Node *p = L->H;
    if (!p) {
        L->H = node;
    } else {
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }
}

int subset(List *A, List *B) {
    Node *p = A->H;
    Node *q = B->H;

    while (p) {
        if (!q || p->elem < q->elem) {
            return p->elem;
        } else if (p->elem > q->elem) {
            q = q->next;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    return 0;
}