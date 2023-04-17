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

int member(Set *A, int e) {
    if (A == NULL)
        return 0;

    Set *p = A;
    while (1) {
        int a = p->elem;
        if (a < e) {
            if (p->next == NULL)
                return (0);
            else
                p = p->next;
        } else if (a > e)
            return (0);
        else
            return (1);
    }
}

int subset(Set *A, Set *B) {
    if (A == NULL)
        return (0);

    Set *p = A;
    while (1) {
        if (member(B, p->elem)) {
            if (p->next == NULL)
                return (0);
            else
                p = p->next;
        } else
            return (p->elem);
    }
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

    printf("%d\n", subset(A, B));

    return (0);
}