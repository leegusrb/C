#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d\n", &N);

    char *st = (char *) malloc(sizeof(char) * (N + 1));
    scanf("%s\n", st);

    char ch[2];
    scanf("%c %c", &ch[0], &ch[1]);

    int cnt[2] = {0};
    for (char *p = st; *p; p++) {
        if (*p == ch[0]) {
            cnt[0]++;
        }

        if (*p == ch[1]) {
            cnt[1]++;
        }
    }

    printf("%d %d\n", cnt[0], cnt[1]);

    free(st);
}