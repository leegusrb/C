#include <stdio.h>

int H[100], n = 0;

void insertItem(int k);
int removeMax();

void upHeap(int i);
void downHeap(int i);

void swap(int *p, int *q);
void printHeap();

int main(){
    char c;
    int k;

    while(1){
        scanf("%c", &c);
        if(c == 'i'){
            scanf("%d", &k);
            insertItem(k);
            printf("0\n");
        }else if(c == 'd'){
            printf("%d\n", removeMax());
        }else if(c == 'p'){
            printHeap();
        }else if(c == 'q'){
            break;
        }
        getchar();
    }

    return 0;
}

void insertItem(int k){
    H[++n] = k;
    upHeap(n);
}

int removeMax(){
    int k = H[1];

    H[1] = H[n--];
    downHeap(1);

    return k;
}

void upHeap(int i){
    if(i == 1) return;

    if(H[i] > H[i / 2]){
        swap(H + i, H + i / 2);
        upHeap(i / 2);
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