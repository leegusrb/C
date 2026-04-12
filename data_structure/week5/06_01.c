#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
  int coef;
  int exp;
  struct Term *next;
} Term;

typedef struct {
  Term *H;
} Poly;

void init(Poly *P) {
  P->H = (Term *)malloc(sizeof(Term));
  P->H->next = NULL;
}

void appendTerm(Term **k, int c, int e) {
  Term *t = (Term *)malloc(sizeof(Term));
  t->coef = c;
  t->exp = e;
  t->next = NULL;

  (*k)->next = t;
  *k = t;
}

Poly addPoly(Poly *x, Poly *y) {
  Poly result;
  init(&result);

  Term *i = x->H->next;
  Term *j = y->H->next;
  Term *k = result.H;

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

  return result;
}

void print(Poly *P) {
  Term *p = P->H->next;
  while (p) {
    printf(" %d %d", p->coef, p->exp);
    p = p->next;
  }
  printf("\n");
}

int main() {
  Poly p1, p2;
  init(&p1);
  init(&p2);

  int n;
  scanf("%d", &n);

  Term *k = p1.H;
  for (int i = 0; i < n; i++) {
    int c, e;
    scanf("%d %d", &c, &e);
    appendTerm(&k, c, e);
  }

  scanf("%d", &n);

  k = p2.H;
  for (int i = 0; i < n; i++) {
    int c, e;
    scanf("%d %d", &c, &e);
    appendTerm(&k, c, e);
  }

  Poly result = addPoly(&p1, &p2);
  print(&result);

  return 0;
}