#include <stdio.h>
#include <stdlib.h>

int M;

typedef struct hashNode{
    int key;
    struct hashNode *next;
}hashNode;

typedef struct{
    hashNode *head;
}hashType;

void insertItem(hashType *H, int k);
int findElement(hashType *H, int k);
int removeElement(hashType *H, int k);
void print(hashType *H);

int h(int x);
void init(hashType *H);

int main(){
    scanf("%d", &M);

    hashType *H = (hashType *)malloc(sizeof(hashType) * M);
    init(H);

    while(1){
        char c;
        int k;

        getchar();
        scanf("%c", &c);

        if(c == 'i'){
            scanf("%d", &k);
            insertItem(H, k);
        }else if(c == 's'){
            scanf("%d", &k);
            printf("%d\n", findElement(H, k));
        }else if(c == 'd'){
            scanf("%d", &k);
            printf("%d\n", removeElement(H, k));
        }else if(c == 'p'){
            print(H);
        }else if(c == 'e'){
            break;
        }
    }

    return 0;
}

void insertItem(hashType *H, int k){
    int v = h(k);
    hashNode *node = (hashNode *) malloc(sizeof(hashNode));
    node->next = NULL;
    node->key = k;
    hashNode *p = (H + v)->head->next;

    (H + v)->head->next = node;
    if(p){
        node->next = p;
    }
}

int findElement(hashType *H, int k){
    int v = h(k);
    int cnt = 0;

    hashNode *p = (H + v)->head;

    while(p->next){
        p = p->next;
        cnt++;

        if(k == p->key) return cnt;
    }

    return 0;
}

int removeElement(hashType *H, int k){
    int v = h(k);
    int cnt = 1;

    hashNode *p = (H + v)->head;
    hashNode *rem;

    while(p->next){
        if(k == p->next->key) {
            rem = p->next;
            p->next = p->next->next;
            free(rem);
            return cnt;
        }

        cnt++;
        p = p->next;
    }

    return 0;
}

void print(hashType *H){
    for(hashType *p = H; p < H + M; p++){
        hashNode *x = p->head->next;

        while(x){
            printf(" %d", x->key);
            x = x->next;
        }
    }

    printf("\n");
}

int h(int x){
    return x % M;
}

void init(hashType *H){
    for(hashType *p = H; p < H + M; p++){
        hashNode *head = (hashNode *) malloc(sizeof(hashNode));
        head->next = NULL;
        p->head = head;
    }
}