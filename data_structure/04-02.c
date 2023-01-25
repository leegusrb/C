#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int N, X[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int changeN, change[100];
    scanf("%d", &changeN);

    for (int i = 0; i < changeN; i++) {
        scanf("%d", &change[i]);
    }

    for (int i = 1; i < changeN; i++) {
        swap(X + change[0], X + change[i]);
    }

    for (int i = 0; i < N; i++) {
        printf(" %d", X[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}