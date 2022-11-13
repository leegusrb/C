#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *ar = (int *) malloc(sizeof(int) * N);

    for (int *p = ar; p < ar + N; p++) {
        scanf("%d", p);
    }

    int sum = 0;
    for (int *p = ar; p < ar + N; p++) {
        sum += *p;
    }

    printf("%d\n", sum);

    free(ar);
}