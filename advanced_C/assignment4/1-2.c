#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st {
    char *str;
    int cnt1;
    int cnt2;
    int num;
    int pos;
    int result;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct st *st = (struct st *) malloc(sizeof(struct st) * N);
    for (struct st *p = st; p < st + N; p++) {
        char tmp[101];
        scanf("%s", tmp);

        p->str = (char *) malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(p->str, tmp);
        p->cnt1 = 0;
        p->cnt2 = (int) strlen(p->str);

        for (char *q = p->str; *q; q++) {
            if (*q >= '0' && *q <= '9') {
                p->num = *q - '0';
                p->pos = (int) (q - p->str + 1);
            } else if (*q != 'a' && *q != 'e' && *q != 'i' && *q != 'o' && *q != 'u' && *q != 'A' && *q != 'E' && *q != 'I' &&
                       *q != 'O' && *q != 'U') {
                p->cnt1++;
            }
        }
        p->result = p->num * p->pos * p->cnt1 * p->cnt2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].result < st[j + 1].result) {
                struct st tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }

    for (struct st *p = st; p < st + N; p++) {
        printf("%s\n", p->str);
    }

    for (struct st *p = st; p < st + N; p++) {
        free(p->str);
    }
    free(st);
}