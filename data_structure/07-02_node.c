#include <stdio.h>
#include <stdlib.h>

typedef struct Set {
    int elem;
    struct Set *next;
} Set;

Set *makeSet(int e) {
    Set *s = (Set *) malloc(sizeof(Set));

    s->elem = e;
    s->next = NULL;

    return (s);
}

void addLast(Set **p, int e) {
    Set *s = makeSet(e);

    if (*p != NULL)
        (*p)->next = s;
    *p = s;
}

Set *union_ (Set *A, Set *B) {
    if (A == NULL && B == NULL)
        return (NULL);

    Set *p = makeSet(0);

    if (A == NULL) {
        p->elem = B->elem;
        p->next = union_(A, B->next);
    } else if (B == NULL) {
        p->elem = A->elem;
        p->next = union_(A->next, B);
    } else {
        if (A->elem < B->elem) {
            p->elem = A->elem;
            p->next = union_(A->next, B);
        } else if (A->elem > B->elem) {
            p->elem = B->elem;
            p->next = union_(A, B->next);
        } else {
            p->elem = A->elem;
            p->next = union_(A->next, B->next);
        }
    }

    return (p);
}

Set *intersect (Set *A, Set *B) {
    if (A == NULL || B == NULL)
        return (NULL);


    if (A->elem < B->elem) {
        return (intersect(A->next, B));
    } else if (A->elem > B->elem) {
        return (intersect(A, B->next));
    } else {
        Set *p = makeSet(0);
        p->elem = A->elem;
        p->next = intersect(A->next, B->next);
        return (p);
    }
}

void print(Set *p) {
    while (p) {
        printf(" %d", p->elem);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Set *A = NULL;
    Set *B = NULL;

    int n, e;
    scanf("%d", &n);

    Set *p = A;
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        addLast(&p, e);
        if (i == 0)
            A = p;
    }

    scanf("%d", &n);

    p = B;
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        addLast(&p, e);
        if (i == 0)
            B = p;
    }

    p = union_(A, B);
    if (p)
        print(p);
    else
        printf(" 0\n");

    p = intersect(A, B);
    if (p)
        print(p);
    else
        printf(" 0\n");

    return (0);
}