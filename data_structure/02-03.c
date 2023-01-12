#include <stdio.h>
#include <stdlib.h>

int *prefixAverages1(int *X, int n);

int *prefixAverages2(int *X, int n);

int main() {
    int n;
    scanf("%d", &n);

    int *X = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    int *A = prefixAverages1(X, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    A = prefixAverages2(X, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

int *prefixAverages1(int *X, int n) {
    int *A = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += X[j];
        }
        A[i] = (int) (((double) sum / (i + 1)) + 0.5);
    }

    return A;
}

int *prefixAverages2(int *X, int n) {
    int *A = (int *) malloc(sizeof(int) * n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += X[i];
        A[i] = (int) (((double) sum / (i + 1)) + 0.5);
    }

    return A;
}