#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *ar = (int *) malloc(sizeof(int) * N);
    for (int *p = ar; p < ar + N; p++) {
        scanf("%d", p);
    }

    for (int *p = ar; p < ar + N - 1; p++) {
        if (*p > *(p + 1)) {
            int tmp = *p;
            *p = *(p + 1);
            *(p + 1) = tmp;
        }
    }

    for (int *p = ar; p < ar + N; p++) {
        printf("%d\n", *p);
    }
}