#include <stdio.h>
#include <stdlib.h>

int* init(int n);
void input(int *L, int n);
void swap(int *p, int *q);
void print(int *L, int n);

void inPlaceInsertionSort(int *L, int n);

int main(){
    int n;
    scanf("%d", &n);
    
    int *L = init(n);
    input(L, n);
    
    inPlaceInsertionSort(L, n);
    print(L, n);

    return 0;
}

int* init(int n){
    int *L = (int *)malloc(sizeof(int) * n);

    return L;
}

void input(int *L, int n){
    for(int *p = L; p < L + n; p++){
        scanf("%d", p);
    }
}

void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void print(int *L, int n){
    for(int *p = L; p < L + n; p++){
        printf(" %d", *p);
    }
    printf("\n");
}

void inPlaceInsertionSort(int *L, int n){
    for(int i = 1; i < n; i++){
        int j, tmp = L[i];
        for(j = i - 1; j >= 0 && L[j] > tmp; j--){
            L[j + 1] = L[j];
        }
        L[j + 1] = tmp;
    }
}