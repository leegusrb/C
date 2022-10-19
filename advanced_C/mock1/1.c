#include <stdio.h>

void input(int *p, int M);
int* sel_max(int *p, int M);
void output(int *p, int N);

int main(void){
    int in[100], out[100], *max, i, N, M;
    
    scanf("%d %d", &N, &M);
    for (i=0; i<N; i++){
        input(in, M);
        max=sel_max(in, M);
        out[i]=*max;
    }
    output(out, N);
    return 0;
}

void input(int *p, int M){
    for(int *x = p; x < p + M; x++){
        scanf("%d", x);
    }
}

int* sel_max(int *p, int M){
    int max = 0, *maxP = p;
    
    for(int *x = p; x < p + M; x++){
        int cnt = 0;
        
        for(int *y = x; y < p + M; y++){
            if(*x == *y){
                cnt++;
            }
        }
        
        if(cnt > max){
            max = cnt;
            maxP = x;
        }
    }
    
    return maxP;
}

void output(int *p, int N){
    for(int *x = p; x < p + N; x++){
        printf(" %d", *x);
    }
    printf("\n");
}