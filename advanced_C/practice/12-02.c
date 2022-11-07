#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    float *ar = (float *) malloc(sizeof(float) * N);

    for (float *p = ar; p < ar + N; p++) {
        scanf("%f", p);
    }

    float max = ar[0];
    for (float *p = ar + 1; p < ar + N; p++) {
        if (*p > max) {
            max = *p;
        }
    }

    printf("%.2f\n", max);
}