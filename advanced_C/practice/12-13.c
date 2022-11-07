#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *ar = (int *) malloc(sizeof(int) * N);
    for (int *p = ar; p < ar + N; p++) {
        scanf("%d", p);
    }

    int D;
    scanf("%d", &D);

    realloc(ar, sizeof(int) * (N - D));

    for (int *p = ar; p < ar + N - D; p++) {
        printf("%d\n", *p);
    }
}