#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, *L;

void input();

int findPivot(int l, int r);
int inPlacePartition(int l, int r, int k);
void inPlaceQuickSort(int l, int r);

void swap(int *p, int *q);
void print();

int main(){
    scanf("%d", &n);

    L = (int *)malloc(sizeof(int) * n);

    srand(time(NULL));

    input();

    inPlaceQuickSort(0, n - 1);

    print();

    return 0;
}

void input(){
    for(int *p = L; p < L + n; p++){
        scanf("%d", p);
    }
}

int findPivot(int l, int r){
    return rand() % (l - r - 1) + l;
}

int inPlacePartition(int l, int r, int k){
    int p = L[k];
    swap(L + k, L + r);
    int i = l;
    int j = r - 1;

    while(i <= j){
        while(i <= j && L[i] <= p){
            i++;
        }

        while(i <= j && L[j] >= p){
            j--;
        }

        if(i < j){
            swap(L + i, L + j);
        }
    }
    swap(L + i, L + r);

    return i;
}

void inPlaceQuickSort(int l, int r){
    if(l < r){
        int k = findPivot(l, r);
        int p = inPlacePartition(l, r, k);
        inPlaceQuickSort(l, p - 1);
        inPlaceQuickSort(p + 1, r);
    }
}

void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void print(){
    for(int *p = L; p < L + n; p++){
        printf(" %d", *p);
    }
    printf("\n");
}