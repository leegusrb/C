#include <stdio.h>

int mostOnes(int A[][100], int n);

int main() {
    int n, A[100][100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("%d\n", mostOnes(A, n));

    return 0;
}

int mostOnes(int A[][100], int n) {
    int maxRow = 0, j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && A[i][j] == 1) {
            maxRow = i;
            j++;
        }
    }

    return maxRow;
}