#include <stdio.h>
#include <stdlib.h>

int check_row(int **p, int M, int N);

int check_col(int **p, int M, int N);

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int **ar = (int **) malloc(sizeof(int *) * M);
    for (int **p = ar; p < ar + M; p++) {
        *p = (int *) malloc(sizeof(int) * N);
        for (int *q = *p; q < *p + N; q++) {
            *q = 0;
        }
    }

    while (1) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0) break;

        ar[x][y] = z;
    }

    for (int **p = ar; p < ar + M; p++) {
        for (int *q = *p; q < *p + N; q++) {
            printf("%d ", *q);
        }
        printf("\n");
    }

    int row = check_row(ar, M, N), col = check_col(ar, M, N);
    if (row > col) {
        printf("%d\n", row);
    } else {
        printf("%d\n", col);
    }
    
    for (int **p = ar; p < ar + M; p++) {
        free(*p);
    }
    free(ar);

    return 0;
}

int check_row(int **p, int M, int N){
    int max = 0;
    for (int i = 0; i < M; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (p[i][j] == 0) {
                cnt++;
            } else {
                if (cnt > max) {
                    max = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > max) {
            max = cnt;
        }
    }

    return max;
}

int check_col(int **p, int M, int N){
    int max = 0;
    for (int j = 0; j < N; j++) {
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            if (p[i][j] == 0) {
                cnt++;
            } else {
                if (cnt > max) {
                    max = cnt;
                }
                cnt = 0;
            }
        }
        if (cnt > max) {
            max = cnt;
        }
    }

    return max;
}

/*
3 5
0 0 5
0 1 15
0 3 25
1 2 35
2 1 45
2 3 55
0 0 0
 */