#include <stdio.h>

void spiral(int mat[][100], int N, int M);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int mat[100][100];
    spiral(mat, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void spiral(int mat[][100], int N, int M) {
    int x = 0, y = -1;
    int flag = 1;
    int cnt = 1, max = N * M;

    N--;
    while (cnt <= max) {
        for (int i = 0; i < M; i++) {
            y += flag;
            mat[x][y] = cnt++;
        }
        M--;

        for (int i = 0; i < N; i++) {
            x += flag;
            mat[x][y] = cnt++;
        }
        N--;

        flag = -flag;
    }
}