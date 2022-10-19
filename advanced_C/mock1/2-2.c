#include <stdio.h>

int input(int *p);
int *sel_next(int *p, int N, int M);
int number(int *p, int *q);

int main(){
    int x[100], N = input(x), M, *start = x, *end;

    end = sel_next(x, N, 0);
    while(start != end){
        printf("%d\n", number(start, end));
        start = end;
        end = sel_next(x, N, start - x);
    }

    return 0;
}

int input(int *p){
    int N = 0;
    
    for(; ; p++, N++){
        scanf("%d", p);
        if(*p == -1) break;
    }

    return N;
}

int *sel_next(int *p, int N, int M){
    int *end = p + M;

    if(*end < *(end + 1)){
        while(end + 1 < p + N && *(end + 1) > *end){
            end++;
        }
    }else{
        while(end + 1 < p + N && *(end + 1) < *end){
            end++;
        }
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