#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coef, exp;
    struct Term *next;
} Term;

Term *makeTerm(int c, int e) {
    Term *t = (Term *) malloc(sizeof(Term));

    t->coef = c;
    t->exp = e;
    t->next = NULL;

    return (t);
}

void appendTerm(Term **k, int c, int e) {
    Term *t = makeTerm(c, e);

    (*k)->next = t;
    *k = t;
}

Term *addPoly(Term *x, Term *y) {
    Term *result = makeTerm(0, 0);

    Term *i = x->next;
    Term *j = y->next;
    Term *k = result;

    while (i != NULL && j != NULL) {
        if (i->exp > j->exp) {
            appendTerm(&k, i->coef, i->exp);
            i = i->next;
        } else if (i->exp < j->exp) {
            appendTerm(&k, j->coef, j->exp);
            j = j->next;
        } else {
            int sum = i->coef + j->coef;
            if (sum != 0)
                appendTerm(&k, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        appendTerm(&k, i->coef, i->exp);
        i = i->next;
    }

    while (j != NULL) {
        appendTerm(&k, j->coef, j->exp);
        j = j->next;
    }

    return (result);
}

void print(Term *H) {
    Term *p = H->next;
    while (p) {
        printf(" %d %d", p->coef, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Term *x = makeTerm(0, 0);
    Term *y = makeTerm(0, 0);

    int n, c, e;
    scanf("%d", &n);

    Term *k = x;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        appendTerm(&k, c, e);
    }

    scanf("%d", &n);

    k = y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        appendTerm(&k, c, e);
    }

    Term *res = addPoly(x, y);
    print(res);

    return (0);
}