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

void init(hashType *H);

void insertItem(hashType *H, int k);
int findElement(hashType *H, int k);
int removeElement(hashType *H, int k);
void print(hashType *H);

int h(int x);

int main(){
    char c;
    int k;

    scanf("%d", &M);

    hashType *H = (hashType *)malloc(sizeof(hashType) * M);
    init(H);

    while(1){
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

void init(hashType *H){
    for(hashType *p = H; p < H + M; p++){
        hashNode *head = (hashNode *)malloc(sizeof(hashNode *));
        head->next = NULL;
        p->head = head;
    }
}

void insertItem(hashType *H, int k){
    int v = h(k);
    hashNode *node = (hashNode *)malloc(sizeof(hashNode));
    hashNode *p = H[v].head;

    node->key = k;
    node->next = p->next;

    p->next = node;
}

int findElement(hashType *H, int k){
    int v = h(k), cnt = 1;
    hashNode *p = H[v].head->next;

    while(p){
        if(p->key == k){
            return cnt;
        }
        p = p->next;
        cnt++;
    }

    return 0;
}

int removeElement(hashType *H, int k){
    int v = h(k), cnt = 1;
    hashNode *p = H[v].head, *q;

    while(p->next){
        if(p->next->key == k){
            q = p->next;
            p->next = q->next;
            free(q);
            return cnt;
        }
        p = p->next;
        cnt++;
    }

    return 0;
}

void print(hashType *H){
    for(hashType *p = H; p < H + M; p++){
        for(hashNode *q = p->head->next; q; q = q->next){
            printf(" %d", q->key);
        }
    }
    printf("\n");
}

int h(int x){
    return x % M;
}