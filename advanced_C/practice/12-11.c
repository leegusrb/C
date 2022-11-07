#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ar = (int *) malloc(sizeof(int) * 5);
    int i, size = 5;

    for (i = 0; i < 20; i++) {
        if (i >= size) {
            int *new = (int *) malloc(sizeof(int) * (size + 3));
            for (int j = 0; j < size; j++) {
                new[j] = ar[j];
            }

            ar = (int *) malloc(sizeof(int) * (size + 3));
            for (int j = 0; j < size; j++) {
                ar[j] = new[j];
            }

            size += 3;
        }

        scanf("%d", &ar[i]);

        if (ar[i] == -1) break;
    }

    for (int *p = ar; p < ar + i + 1; p++) {
        printf(" %d", *p);
    }
    printf("\n");
}