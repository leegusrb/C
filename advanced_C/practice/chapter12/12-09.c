#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char **st = (char **) malloc(sizeof(char *) * N);
    for (char **p = st; p < st + N; p++) {
        *p = (char *) malloc(sizeof(char) * 101);
    }

    for (char **p = st; p < st + N; p++) {
        gets(*p);
    }

    for (char **p = st; p < st + N; p++) {
        for (char **q = st; q < p; q++) {
            if (strlen(*p) > strlen(*q)) {
                char *tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }
    }

    for (char **p = st; p < st + N; p++) {
        printf("%s\n", *p);
    }
        for (char **p = st; p < st + N; p++) {
        free(*p);
    }
    free(st);
}