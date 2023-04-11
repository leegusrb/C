#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int elem;
    struct Node *next;
} Node;

typedef struct {
    Node *H;
} List;

Node *makeNode(int e) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->elem = e;
    node->next = NULL;

    return (node);
}

List *makeList() {
    List *L = (List *) malloc(sizeof(List));

    L->H = makeNode(0);

    return (L);
}

void append(List *L, int e) {
    Node *node = makeNode(e);

    Node *p = L->H;
    while (p->next)
        p = p->next;

    p->next = node;
}

List *union_(List *A, List *B) {
    List *L = makeList();

    Node *p = A->H->next;
    Node *q = B->H->next;

    while (p && q) {
        if (p->elem < q->elem) {
            append(L, p->elem);
            p = p->next;
        } else if (p->elem > q->elem) {
            append(L, q->elem);
            q = q->next;
        } else {
            append(L, p->elem);
            p = p->next;
            q = q->next;
        }
    }

    while (p) {
        append(L, p->elem);
        p = p->next;
    }

    while (q) {
        append(L, q->elem);
        q = q->next;
    }

    return (L);
}

List *intersect(List *A, List *B) {
    List *L = makeList();

    Node *p = A->H->next;
    Node *q = B->H->next;

    while (p && q) {
        if (p->elem < q->elem) {
            p = p->next;
        } else if (p->elem > q->elem) {
            q = q->next;
        } else {
            append(L, p->elem);
            p = p->next;
            q = q->next;
        }
    }

    return (L);
}

void print(List *L) {
    Node *p = L->H->next;

    if (!p) {
        printf(" 0");
    } else {
        for (; p; p = p->next)
            printf(" %d", p->elem);
    }
    printf("\n");
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

    print(union_(A, B));
    print(intersect(A, B));

    return (0);
}