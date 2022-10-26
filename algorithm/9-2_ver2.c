#include <stdio.h>
#include <stdlib.h>

int M, n;

int insertItem(int *H, int k);
int findElement(int *H, int k);

int h(int x);
int getNextBucket(int v, int i);

int main(){
    scanf("%d %d", &M, &n);

    int *H = (int *) malloc(sizeof(int) * M);

    while(1){
        char c;
        int k;

        getchar();
        scanf("%c", &c);

        if(c == 'i'){
            scanf("%d", &k);
            printf("%d\n", insertItem(H, k));
        }else if(c == 's'){
            scanf("%d", &k);
            int i = findElement(H, k);
            if(i != -1){
                printf("%d %d\n", i, k);
            }else{
                printf("%d\n", i);
            }
        }else if(c == 'e'){
            break;
        }
    }

    return 0;
}

int insertItem(int *H, int k){
    int v = h(k);
    int i = 0;

    while(i < n){
        int b = getNextBucket(v, i);
        if(H[b] == 0){
            H[b] = k;

            for(int x = 0; x < i; x++){
                printf("C");
            }

            return b;
        }

        i++;
    }

    return -1;
}

int findElement(int *H, int k){
    int v = h(k);
    int i = 0;

    while(i < n){
        int b = getNextBucket(v, i);
        if(H[b] == 0){
            return -1;
        }else if(H[b] == k){
            return b;
        }else{
            i++;
        }
    }

    return -1;
}

int h(int x){
    return x % M;
}

int getNextBucket(int v, int i){
    return (v + i) % M;
}