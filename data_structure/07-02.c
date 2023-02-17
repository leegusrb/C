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

List *union_(List *A, List *B);

List *intersect(List *A, List *B);

void print(List *L);

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

    List *U = union_(A, B);
    List *I = intersect(A, B);

    print(U);
    print(I);

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

List *union_(List *A, List *B) {
    List *U = (List *) malloc(sizeof(List));
    init(U);

    Node *p = A->H;
    Node *q = B->H;

    while (p && q) {
        if (p->elem < q->elem) {
            add(U, p->elem);
            p = p->next;
        } else if (p->elem > q->elem) {
            add(U, q->elem);
            q = q->next;
        } else {
            add(U, p->elem);
            p = p->next;
            q = q->next;
        }
    }

    while (p) {
        add(U, p->elem);
        p = p->next;
    }

    while (q) {
        add(U, q->elem);
        q = q->next;
    }

    return U;
}

List *intersect(List *A, List *B) {
    List *I = (List *) malloc(sizeof(List));
    init(I);

    Node *p = A->H;
    Node *q = B->H;

    while (p && q) {
        if (p->elem < q->elem) {
            p = p->next;
        } else if (p->elem > q->elem) {
            q = q->next;
        } else {
            add(I, p->elem);
            p = p->next;
            q = q->next;
        }
    }

    return I;
}

void print(List *L) {
    if (!L->H) {
        printf("0");
    }

    for (Node *p = L->H; p; p = p->next) {
        printf(" %d", p->elem);
    }
    printf("\n");
}