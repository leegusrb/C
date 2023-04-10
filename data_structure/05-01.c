#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *H, *T;
} List;

void initList(List *L) {
    L->H = (Node *) malloc(sizeof(Node));
    L->T = (Node *) malloc(sizeof(Node));

    L->H->next = L->T;
    L->T->prev = L->H;
}

int countList(List *L) {
    int cnt = 0;
    
    for (Node *p = L->H->next; p != L->T; p = p->next) 
        cnt++;
    
    return (cnt);
}

Node *makeNode(char e) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->elem = e;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}

void add(List *L, int r, char e) {
    if (countList(L) < r - 1) {
        printf("invalid position\n");
        return ;
    }
    Node *node = makeNode(e);

    Node *p = L->H;
    for (int i = 0; i < r - 1; i++)
        p = p->next;
    Node *n = p->next;

    node->prev = p;
    node->next = n;

    p->next = node;
    n->prev = node;
}

char delete(List *L, int r) {
    if (countList(L) < r) {
        printf("invalid position\n");
        return 0;
    }
    Node *del = L->H;
    for (int i = 0; i < r; i++)
        del = del->next;

    Node *p = del->prev;
    Node *n = del->next;

    p->next = n;
    n->prev = p;

    char e = del->elem;
    free(del);

    return (e);
}

char get(List *L, int r) {
    if (countList(L) < r) {
        printf("invalid position\n");
        return 0;
    }
    Node *p = L->H;
    for (int i = 0; i < r; i++)
        p = p->next;

    return (p->elem);
}

void print(List *L) {
    for (Node *p = L->H->next; p != L->T; p = p->next)
        printf("%c", p->elem);
    printf("\n");
}

int main() {
    List *L = (List *) malloc(sizeof(List));
    initList(L);

    int n, r;
    char c, e;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &c);
        if (c == 'A') {
            scanf("%d %c", &r, &e);
            add(L, r, e);
        } else if (c == 'D') {
            scanf("%d", &r);
            e = delete(L, r);
        } else if (c == 'G') {
            scanf("%d", &r);
            e = get(L, r);
            if (e) 
                printf("%c\n", e);
        } else if (c == 'P') {
            print(L);
        }
    }

    return (0);
}