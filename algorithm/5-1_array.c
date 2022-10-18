#include <stdio.h>

int L[100], L2[100], n = 0;

void input();

void mergeSort(int l, int r);
void merge(int l, int m, int r);

void print();

int main(){
    scanf("%d", &n);
    input();

    mergeSort(0, n-1);

    print();

    return 0;
}

void input(){
    for(int *p = L; p < L + n; p++){
        scanf("%d", p);
    }
}

void mergeSort(int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

void merge(int l, int m, int r){
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r){
        if(L[i] < L[j]){
            L2[k++] = L[i++];
        }else{
            L2[k++] = L[j++];
        }
    }

    while(i <= m){
        L2[k++] = L[i++];
    }

    while(j <= r){
        L2[k++] = L[j++];
    }

    for(int i = l; i <= r; i++){
        L[i] = L2[i];
    }
}

void print(){
    for(int *p = L; p < L + n; p++){
        printf(" %d", *p);
    }
    printf("\n");
}