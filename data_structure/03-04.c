#include <stdio.h>

int arrayMax(int *A, int n);

int max(int a, int b);

int main() {
    int N, A[20];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("%d\n", arrayMax(A, N));

    return 0;
}

int arrayMax(int *A, int n) {
    if (n == 1) return A[0];

    return max(A[n - 1], arrayMax(A, n - 1));
}

int max(int a, int b) {
    if (a > b) return a;

    return b;
}