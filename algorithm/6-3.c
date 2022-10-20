#include <stdio.h>

int input(int a, int b, int n);
void findK(int *a, int *b, char c);

int main(){
    int a, b, n;

    scanf("%d %d %d\n", &a, &b, &n);

    printf("%d\n", input(a, b, n));

    return 0;
}

int input(int a, int b, int n){
    char c;

    for(int i = 0; i < n; i++){
        scanf("%c", &c);
        findK(&a, &b, c);
    }

    return a;
}

void findK(int *a, int *b, char c){
    int m = (*a + *b) / 2;

    if(c == 'Y'){
        *a = m + 1;
    }else{
        *b = m;
    }
}