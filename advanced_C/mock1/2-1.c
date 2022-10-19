#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main(){
    int x[100], N = input(x), M;

    scanf("%d", &M);

    printf("%d\n", number(x + M, sel_next(x, N, M)));

    return 0;
}

int input(int *p){
    int N = 0;
    
    for(; ; p++, N++){
        scanf("%d", p);
        if(*p == -1) break;
    }

    return N + 1;
}

int *sel_next(int *p, int N, int M){
    int *end = p + M;

    while(end < p + N && *(end + 1) > *end){
        end++;
    }

    return end;
}

int number(int *p, int *q){
    int num = 0;

    for(; p - 1 != q; p++){
        num = num * 10 + *p;
    }

    return num;
}