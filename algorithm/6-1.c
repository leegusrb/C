#include <stdio.h>
#include <stdlib.h>

int n, k, *L;

void input();

int findElement(int k, int l, int r);

int main(){
    scanf("%d %d", &n, &k);
    L = (int *)malloc(sizeof(int) * n);
    input();
    
    printf("%d\n", findElement(k, 0, n - 1));

    return 0;
}

void input(){
    for(int *p = L; p < L + n; p++){
        scanf("%d", p);
    }
}

int findElement(int k, int l, int r){
    if(l > r) return r;

    int mid = (l + r) / 2;

    if(k == L[mid]){
        return mid;
    }else if(k < L[mid]){
        return findElement(k, l, mid - 1);
    }else{
        return findElement(k, mid + 1, r);
    }
    
}