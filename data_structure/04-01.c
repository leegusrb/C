#include <stdio.h>

void reverse(int *X, int start, int end);

void swap(int *a, int *b);

int main() {
    int N, X[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int revN;
    scanf("%d", &revN);

    for (int i = 0; i < revN; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        reverse(X, start, end);
    }

    for (int i = 0; i < N; i++) {
        printf(" %d", X[i]);
    }
    printf("\n");

    return 0;
}

void reverse(int *X, int start, int end) {
    for (int j = 0; j <= (end - start) / 2; j++) {
        swap(X + start + j, X + end - j);
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}