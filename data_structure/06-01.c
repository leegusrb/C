#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef, exp;
    struct Node *next;
} Node;

typedef struct {
    Node *H;
} List;

void init(List *L) {
    L->H = (Node *) malloc(sizeof(Node));
    L->H->next = NULL;
}

void appendTerm(List *L, int c, int e) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->coef = c;
    node->exp = e;
    node->next = NULL;

    Node *p = L->H;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
}

List *addPoly(List *x, List *y) {
    List *result = (List *) malloc(sizeof(List));
    init(result);

    Node *p = x->H;
    Node *q = y->H;

    while (p && q) {
        if (p->exp > q->exp) {
            appendTerm(result, p->coef, p->exp);
            p = p->next;
        } else if (p->exp < q->exp) {
            appendTerm(result, q->coef, q->exp);
            q = q->next;
        } else {
            int sum = p->coef + q->coef;
            if (sum != 0)
                appendTerm(result, sum, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p) {
        appendTerm(result, p->coef, p->exp);
        p = p->next;
    }
    while (q) {
        appendTerm(result, q->coef, q->exp);
        q = q->next;
    }

    return (result);
}

void print(List *L) {
    for (Node *p = L->H->next; p; p = p->next) {
        printf(" %d %d", p->coef, p->exp);
    }
    printf("\n");
}

int main() {
    List *x = (List *) malloc(sizeof(List));
    List *y = (List *) malloc(sizeof(List));
    init(x);
    init(y);

    int n, c, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        appendTerm(x, c, e);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        appendTerm(y, c, e);
    }

    List *result = addPoly(x, y);
    print(result);

    return (0);
}