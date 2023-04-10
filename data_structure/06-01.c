#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef, exp;
    struct Node *next;
} Node;

typedef struct {
    Node *H;
} List;

List *makeList() {
    List *L = (List *) malloc(sizeof(List));

    L->H = (Node *) malloc(sizeof(Node));
    L->H->next = NULL;

    return (L);
}

Node *makeNode(int c, int e) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->coef = c;
    node->exp = e;
    node->next = NULL;

    return (node);
}

void appendTerm(List *L, int c, int e) {
    Node *node = makeNode(c, e);

    Node *p = L->H;
    while (p->next != NULL)
        p = p->next;
    p->next = node;
}

List *addPoly(List *x, List *y) {
    List *result = makeList();

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
    for (; p; p = p->next)
        appendTerm(result, p->coef, p->exp);
    for (; q; q = q->next)
        appendTerm(result, q->coef, q->exp);

    return (result);
}

void print(List *L) {
    for (Node *p = L->H->next; p; p = p->next) {
        printf(" %d %d", p->coef, p->exp);
    }
    printf("\n");
}

int main() {
    List *x = makeList();
    List *y = makeList();

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