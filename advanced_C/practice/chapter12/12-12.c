#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char **st = (char **) malloc(sizeof(char *) * N);
    char *tmp = (char *) malloc(sizeof (char) * 101);
    for (char **p = st; p < st + N; p++) {
        scanf("%s", tmp);
        *p = (char *) malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(*p, tmp);
    }

    for (char **p = st; p < st + N; p++) {
        for (char **q = st; q < p; q++) {
            if (strcmp(*p, *q) < 0) {
                tmp = *p;
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
    free(tmp);
}