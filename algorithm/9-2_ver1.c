#include <stdio.h>
#include <stdlib.h>

int M, n;

typedef struct{
    int x, c;
}bucket;

int h(int x);

void init(bucket *H);

void insertItem(bucket *H, int k);
int findElement(bucket *H, int k);

int main(){
    char c;
    int x;

    scanf("%d %d", &M, &n);

    bucket *H = (bucket *)malloc(sizeof(bucket) * M);
    init(H);

    while(1){
        getchar();
        scanf("%c", &c);
        if(c == 'i'){
            scanf("%d", &x);
            insertItem(H, x);
        }else if(c == 's'){
            scanf("%d", &x);
            findElement(H, x);
        }else if(c == 'e'){
            break;
        }
    }

    return 0;
}

void init(bucket *H){
    for(bucket *p = H; p < H + M; p++){
        p->x = 0;
        p->c = 0;
    }
}

void insertItem(bucket *H, int x){
    int v = h(x), cnt = 0;

    while(H[v].x){
        cnt++;
        v++;
        v = h(v);
    }

    H[v].x = x;
    H[v].c = cnt;
    for(int i = 0; i < H[v].c; i++){
        printf("C");
    }
    printf("%d\n", v);
}

int findElement(bucket *H, int x){
    int v = h(x);

    while(H[v].x && H[v].x != x){
        v++;
        v = h(v);
    }

    if(H[v].x == 0){
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n", v, x);

    return x;
}

int h(int x){
    return x % M;
}