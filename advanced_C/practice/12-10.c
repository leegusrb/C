#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *ar1 = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        ar1[i] = i;
    }

    int *ar2 = (int *) malloc(sizeof(int) * (N - 1));
    for (int i = 0; i < N - 1; i++) {
        if (i < N / 2) {
            ar2[i] = i;
        } else {
            ar2[i] = i + 1;
        }
    }

    for (int *p = ar2; p < ar2 + N - 1; p++) {
        printf(" %d", *p);
    }
    printf("\n");

    free(ar1);
    free(ar2);
}