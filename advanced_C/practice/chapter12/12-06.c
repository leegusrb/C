#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char *ar = (char *) malloc(sizeof(char) * N);
    for (char *p = ar; p < ar + N; p++) {
        scanf("%c", p);
    }

    int cnt = 0;
    for (char *p = ar; p < ar + N; p++) {
        if(!strncmp(p, "cat", 3)) {
            cnt++;
        }
    }

    printf("%d\n", cnt);

    free(ar);
}