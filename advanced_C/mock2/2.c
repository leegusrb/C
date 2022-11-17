#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d ", &N);

    char X[101];
    scanf("%s\n", X);
    int len = (int) strlen(X);

    char **Y = (char **) malloc(sizeof(char *) * N);
    for (char **p = Y; p < Y + N; p++) {
        char str[101];
        gets(str);
        *p = (char *) malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(*p, str);
    }

    int maxCnt = 0;
    char *maxStr = 0;
    for (char **p = Y; p < Y + N; p++) {
        int cnt = 0;
        for (char *q = *p; *q; q++) {
            if (strncmp(q, X, len) == 0) {
                cnt++;
                q += len - 1;
            }
        }

        if (cnt > maxCnt) {
            maxCnt = cnt;
            maxStr = *p;
        }
    }

    if (maxCnt == 0) {
        printf("NONE");
    } else {
        printf("%s\n", maxStr);
    }

    for (char **p = Y; p < Y + N; p++) {
        free(*p);
    }
    free(Y);

    return 0;
}