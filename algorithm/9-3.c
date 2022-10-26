#include <stdio.h>
#include <stdlib.h>

int M, n, q;

typedef struct{
    int x, c;
}bucket;

int h(int x);
int h2(int x);

void init(bucket *H);

void insertItem(bucket *H, int k);
int findElement(bucket *H, int k);
void print(bucket *H);

int main(){
    char c;
    int x;

    scanf("%d %d %d", &M, &n, &q);

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
        }else if(c == 'p'){
            print(H);
        }else if(c == 'e'){
            print(H);
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
        v += cnt * h2(x);
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
    int v = h(x), cnt = 0;

    while(H[v].x && H[v].x != x){
        cnt++;
        v += cnt * h2(x);
        v = h(v);
    }

    if(H[v].x == 0){
        printf("-1\n");
        return 0;
    }
    printf("%d %d\n", v, x);

    return x;
}

void print(bucket *H){
    for(int i = 0; i < M; i++){
        printf(" %d", H[i].x);
    }
    printf("\n");
}

int h(int x){
    return x % M;
}

int h2(int x){
    return q - (x % q);
}