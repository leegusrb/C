#include <stdio.h>

int H[100], n = 0;

void input(int n);

void rBuildHeap(int i);

void downHeap(int i);

void swap(int *p, int *q);
void printHeap();

int main(){
    scanf("%d", &n);
    input(n);

    rBuildHeap(1);

    printHeap();

    return 0;
}

void input(int n){
    for(int *p = H + 1; p <= H + n; p++){
        scanf("%d", p);
    }
}

void rBuildHeap(int i){
    if(i * 2 <= n){
        rBuildHeap(i * 2);
        rBuildHeap(i * 2 + 1);
        downHeap(i);
    }
}

void downHeap(int i){
    if(i * 2 > n) return;

    int big = i * 2;
    if(i * 2 + 1 <= n && H[i * 2] < H[i * 2 + 1]){
        big += 1;
    }

    if(H[i] < H[big]){
        swap(H + i, H + big);
        downHeap(big);
    }
}

void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void printHeap(){
    for(int *p = H + 1; p <= H + n; p++){
        printf(" %d", *p);
    }
    printf("\n");
}