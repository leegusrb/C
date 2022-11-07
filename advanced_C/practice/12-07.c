#include <stdio.h>
#include <stdlib.h>

int main() {
    int col, row;
    scanf("%d %d", &col, &row);

    char **ar = (char **) malloc(sizeof(char *) * row);
    for (char **p = ar; p < ar + row; p++) {
        *p = (char *) malloc(sizeof(char) * col);
    }

    char alp = 'a';
    for (char **p = ar; p < ar + row; p++) {
        for (char *q = *p; q < *p + col; q++) {
            *q = alp++;
            if (alp == 'z' + 1) {
                alp = 'A';
            }
            if (alp == 'Z' + 1) {
                alp = 'a';
            }
        }
    }

    for (char **p = ar; p < ar + row; p++) {
        for (char *q = *p; q < *p + col; q++) {
            printf("%c ", *q);
        }
        printf("\n");
    }

    for (char **p = ar; p < ar + row; p++) {
        free(*p);
    }
    free(ar);
}