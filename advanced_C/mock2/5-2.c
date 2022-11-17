#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *str;
    int words;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct string *string = (struct string *) malloc(sizeof(struct string) * N);
    for (struct string *p = string; p < string + N; p++) {
        char tmp[101];
        gets(tmp);

        p->str = (char *) malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(p->str, tmp);

        p->words = 1;
        for (char *q = p->str; *q; q++) {
            if (*q == ' ') {
                p->words++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (string[j].words < string[j + 1].words) {
                struct string tmp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = tmp;
            }
        }
    }

    for (struct string *p = string; p < string + N; p++) {
        char **div = (char **) malloc(sizeof(char *) * p->words);
        char *start = p->str;
        int x = 0, y = 0;
        for (char *q = p->str; q <= p->str + strlen(p->str); q++) {
            if (*q == ' ' || *q == '\0') {
                div[x] = (char *) malloc(sizeof(char) * (y + 1));
                strncpy(div[x], start, y);
                div[x++][y] = '\0';
                start = q + 1;
                y = 0;
            } else {
                y++;
            }
        }

        int maxIdx = 0, maxCnt = 0;
        for (int i = 0; i < p->words; i++) {
            int cnt = 0;
            for (int j = i; j < p->words; j++) {
                if (strcmp(div[i], div[j]) == 0) {
                    cnt++;
                }
            }

            if (cnt > maxCnt || (cnt == maxCnt && strcmp(div[i], div[maxIdx]) < 0)) {
                maxCnt = cnt;
                maxIdx = i;
            }
        }

        printf("%s %d %s %d\n", p->str, p->words, div[maxIdx], maxCnt);

        for (char **p1 = div; p1 < div + p->words; p1++) {
            free(*p1);
        }
        free(div);
    }

    for (struct string *p = string; p < string + N; p++) {
        free(p->str);
    }
    free(string);

    return 0;
}
/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later
 */