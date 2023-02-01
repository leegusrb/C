#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *prev, *next;
} Node;

typedef struct List {
    Node *header, *trailer;
} List;

void init(List *L);

void add(List *L, int r, char e);

char delete(List *L, int r);

char get(List *L, int r);

int count(List *L);

void print(List *L);

int main() {
    List *L = (List *) malloc(sizeof(List));

    init(L);

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        getchar();

        char c;
        scanf("%c", &c);

        if (c == 'A') {
            int r;
            char e;

            scanf("%d %c", &r, &e);
            add(L, r, e);
        } else if (c == 'D') {
            int r;
            scanf("%d", &r);

            delete(L, r);
        } else if (c == 'G') {
            int r;
            scanf("%d", &r);

            char e = get(L, r);
            if (e) {
                printf("%c\n", e);
            }
        } else if (c == 'P') {
            print(L);
        }
    }

    return 0;
}

void init(List *L) { // 연결리스트 초기화
    L->header = (Node *) malloc(sizeof(Node));  // header 노드 만들기
    L->trailer = (Node *) malloc(sizeof(Node)); // trailer 노드 만들기

    L->header->next = L->trailer;
    L->trailer->prev = L->trailer;
}

void add(List *L, int r, char e) {
    if (count(L) + 1 < r) {
        printf("invalid position\n");
        return;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    node->elem = e;
    node->prev = NULL;
    node->next = NULL;

    Node *p = L->header;        // 추가할 노드의 이전 노드
    Node *q = L->header->next;  // 추가할 노드의 다음 노드

    for (int i = 1; i < r; i++) {
        p = q;
        q = q->next;
    }

    p->next = node;
    q->prev = node;

    node->prev = p;
    node->next = q;
}

char delete(List *L, int r) {
    if (count(L) < r) {
        printf("invalid position\n");
        return 0;
    }

    Node *p = L->header->next;  // 삭제할 노드

    for (int i = 1; i < r; i++) {
        p = p->next;
    }

    char e = p->elem;
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);

    return e;
}

char get(List *L, int r) {
    if (count(L) < r) {
        printf("invalid position\n");
        return 0;
    }

    Node *p = L->header->next;  // 가져올 노드

    for (int i = 1; i < r; i++) {
        p = p->next;
    }

    return p->elem;
}

int count(List *L) {
    Node *p = L->header;
    int cnt = 0;

    while (p->next != L->trailer) {
        cnt++;
        p = p->next;
    }

    return cnt;
}

void print(List *L) {
    Node *p = L->header->next;

    while (p != L->trailer) {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}