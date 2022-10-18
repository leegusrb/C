#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int e;
    struct listNode *next;
}listNode;

typedef struct{
    listNode *H;
}listType;

void init(listType *L);
int size(listType *L);
void push(listType *L, int e);
int pop(listType *L);

void mergeSort(listType *L);
void merge(listType *L1, listType *L2);
listType* partition(listType *L, int k);

void print(listType *L);

int main(){
    listType *L = (listType *)malloc(sizeof(listType));
    int n, e;

    init(L);
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &e);
        push(L, e);
    }

    mergeSort(L);

    print(L);

    return 0;
}

void init(listType *L){
    L->H = NULL;
}

int size(listType *L){
    int s = 0;
    listNode *p = L->H;

    while(p){
        p = p->next;
        s++;
    }

    return s;
}

void push(listType *L, int e){
    listNode *node = (listNode *)malloc(sizeof(listNode));
    node->e = e;
    node->next = NULL;

    listNode *p = L->H;

    if(!p){
        L->H = node;
    }else{
        while(p->next){
            p = p->next;
        }
        p->next = node;
    }
}

int pop(listType *L){
    int e = L->H->e;
    listNode *p = L->H;

    L->H = p->next;
    free(p);

    return e;
}

void mergeSort(listType *L){
    if(size(L) > 1){
        listType *L2 = partition(L, size(L) / 2);
        mergeSort(L);
        mergeSort(L2);
        merge(L, L2);
    }
}

void merge(listType *L, listType *L2){
    listType *L1 = (listType *)malloc(sizeof(listType));
    init(L1);

    while(L->H && L2->H){
        if(L->H->e < L2->H->e){
            push(L1, pop(L));
        }else{
            push(L1, pop(L2));
        }
    }

    while(L->H){
        push(L1, pop(L));
    }

    while(L2->H){
        push(L1, pop(L2));
    }
    
    while(L1->H){
        push(L, pop(L1));
    }
}

listType* partition(listType *L, int k){
    listType *L2 = (listType *)malloc(sizeof(listType));
    init(L2);

    for(int i = 0; i < k; i++){
        push(L2, pop(L));
    }

    return L2;
}

void print(listType *L){
    for(listNode *p = L->H; p; p = p->next){
        printf(" %d", p->e);
    }
    printf("\n");
}