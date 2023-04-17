#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *prev, *next;
} Node;

Node *makeNode(char e) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->elem = e;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}

void add(Node *H, Node *T, int r, char e) {
    Node *node = makeNode(e);

    Node *p = H;
    for (int i = 0; i < r - 1; i++) {
        p = p->next;
        if (p == T) {
            printf("invalid position\n");
            return;
        }
    }

    node->prev = p;
    node->next = p->next;

    p->next = node;
    node->next->prev = node;
}

char delete(Node *H, Node *T, int r) {
    Node *p = H;
    for (int i = 0; i < r; i++){
        p = p->next;
        if (p == T) {
            printf("invalid position");
            return (0);
        }
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    char e = p->elem;
    free(p);

    return (e);
}

char get(Node *H, Node *T, int r) {
    Node *p = H;
    for (int i = 0; i < r; i++) {
        p = p->next;
        if (p == T) {
            printf("invalid position");
            return (0);
        }
    }

    return (p->elem);
}

void print(Node *H, Node *T) {
    Node *p = H->next;
    while (p != T) {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node *H = makeNode(0);
    Node *T = makeNode(0);
    H->next = T;
    T->next = H;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char c, e;
        int r;

        getchar();
        scanf("%c", &c);

        switch (c) {
            case 'A':
                scanf("%d %c", &r, &e);
                add(H, T, r, e);
                break;
            case 'D':
                scanf("%d", &r);
                e = delete(H, T, r);
                break;
            case 'G':
                scanf("%d", &r);
                e = get(H, T, r);
                if (e)
                    printf("%c\n", e);
                break;
            case 'P':
                print(H, T);
                break;
        }
    }

    return (0);
}