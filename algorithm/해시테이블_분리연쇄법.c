#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct HashNode{
    int key;
    struct HashNode *next;
}HashType;

void init(HashType *HT){
    for(int i = 0; i < M; i++){
        HT[i].key = 0;
        HT[i].next = NULL;
    }
}

int h(int key){
    return key % M;
}

void insertItem(HashType *HT, int key){
    int v = h(key);
    HashType *node = (HashType *)malloc(sizeof(HashType));
    node->key = key;
    node->next = HT[v].next;
    HT[v].next = node;
}

int findElement(HashType *HT, int key){
    int v = h(key);
    int count = 0;
    HashType *p;
    for(p = HT[v].next; p != NULL; p = p->next){
        if(p->key == key){
            count++;
        }
    }

    return count;
}

int removeElement(HashType *HT, int key){
    int v = h(key);
    int count = 0;
    HashType *p = &HT[v];
    HashType *q;

    while(p->next != NULL){
        if(p->next->key == key){
            count++;
            q = p->next;
            p->next = q->next;
            free(q);
        }else{
            p = p->next;
        }
    }

    return count;
}

void printHash(HashType *HT){
    HashType *p;
    for(int i = 0; i < M; i++){
        printf("HT[%02d] : ", i);
        for(p = HT[i].next; p != NULL; p = p->next){
            printf("(%d)", p->key);
        }
        printf("\n");
    }
}

int main(){
    HashType HT[M];
    init(HT);

    srand(time(NULL));

    for(int i = 0; i < 20; i++){
        insertItem(HT, rand() % 40 + 10);
    }
    printHash(HT);

    int key;
    printf("\nInput search key : ");
    scanf("%d", &key);
    printf("There are %d %d.\n", findElement(HT, key), key);

    printf("\nInput delete key : ");
    scanf("%d", &key);
    printf("%d %d deleted.\n", removeElement(HT, key), key);
    printHash(HT);

    return 0;
}