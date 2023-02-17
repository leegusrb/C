#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;

typedef struct {
    Node *header;
} List;

void init(List *L);

void appendTerm(List *L, int c, int e);

List *addPoly(List *x, List *y);

void print(List *L);

int main() {
    List *x = (List *) malloc(sizeof(List));
    List *y = (List *) malloc(sizeof(List));
    init(x);
    init(y);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        appendTerm(x, c, e);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        appendTerm(y, c, e);
    }

    print(addPoly(x, y));

    return 0;
}

void init(List *L) {
    L->header = (Node *) malloc(sizeof(Node));

    L->header->next = NULL;
}

void appendTerm(List *L, int c, int e) {
    Node *t = (Node *) malloc(sizeof(Node));
    t->coef = c;
    t->exp = e;
    t->next = NULL;

    Node *p = L->header;
    while (p->next) {
        p = p->next;
    }
    p->next = t;
}

List *addPoly(List *x, List *y) {
    List *result = (List *) malloc(sizeof(List));
    init(result);

    Node *i = x->header->next;
    Node *j = y->header->next;

    while (i && j) {
        if (i->exp > j->exp) {
            appendTerm(result, i->coef, i->exp);
            i = i->next;
        } else if (i->exp < j->exp) {
            appendTerm(result, j->coef, j->exp);
            j = j->next;
        } else {
            int sum = i->coef + j->coef;
            if (sum != 0) {
                appendTerm(result, sum, i->exp);
            }
            i = i->next;
            j = j->next;
        }
    }

    while (i) {
        appendTerm(result, i->coef, i->exp);
        i = i->next;
    }
    while (j) {
        appendTerm(result, j->coef, j->exp);
        j = j->next;
    }

    return result;
}

void print(List *result) {
    for (Node *p = result->header->next; p; p = p->next) {
        printf(" %d %d", p->coef, p->exp);
    }
    printf("\n");
}