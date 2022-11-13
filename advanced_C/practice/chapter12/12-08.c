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

    char *min = st[0];
    for (char **p = st + 1; p < st + N; p++) {
        if (strlen(*p) < strlen(min)) {
            min = *p;
        }
    }

    printf("%s\n", min);

    for (char **p = st; p < st + N; p++) {
        free(*p);
    }
    free(st);
}