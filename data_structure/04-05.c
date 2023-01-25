#include <stdio.h>

void diagonal(int mat[][100], int N, int M);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int mat[100][100];
    diagonal(mat, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void diagonal(int mat[][100], int N, int M) {
    int cnt = 1;
    int x, y;

    for (int i = 0; i < M; i++) {
        x = 0;
        y = i;

        while (x != N && y != -1) {
            mat[x++][y--] = cnt++;
        }
    }

    for (int i = 1; i < N; i++) {
        x = i;
        y = M - 1;

        while (x != N && y != -1) {
            mat[x++][y--] = cnt++;
        }
    }
}