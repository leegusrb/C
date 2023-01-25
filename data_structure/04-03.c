#include <stdio.h>

void zigzag(int mat[][100], int N);

int main() {
    int N;
    scanf("%d", &N);

    int mat[100][100];
    zigzag(mat, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void zigzag(int mat[][100], int N) {
    int cnt = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == 0) {
                mat[i][j] = cnt++;
            } else {
                mat[i][N - 1 - j] = cnt++;
            }
        }
    }
}