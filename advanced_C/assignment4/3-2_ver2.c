#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subject {
    char *name;
    double score;
};

struct student {
    char *name;
    char id[5];
    int numSubject;
    struct subject *pSub;
    double avg;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);

    for (int i = 0; i < N; i++) {
        char tmp[101];
        gets(tmp);

        int cnt = 1;
        for (char *p = tmp; *p; p++) {
            if (*p == ' ') {
                cnt++;
            }
        }

        char **word = (char **) malloc(sizeof(char *) * cnt);
        char *start = tmp;
        int len = 0, j = 0;
        for (char *q = tmp; q <= tmp + strlen(tmp); q++) {
            if (*q == ' ' || *q == '\0') {
                word[j] = (char *) malloc(sizeof(char) * (len + 1));
                strncpy(word[j], start, len);
                word[j++][len] = '\0';
                start = q + 1;
                len = 0;
            } else {
                len++;
            }
        }

        st[i].name = (char *) malloc(sizeof(char) * (strlen(word[0]) + 1));
        strcpy(st[i].name, word[0]);

        strcpy(st[i].id, word[1]);

        st[i].numSubject = (cnt - 2) / 2;

        st[i].avg = 0;

        st[i].pSub = (struct subject *) malloc(sizeof(struct subject) * st[i].numSubject);
        int k = 2;
        for (struct subject *p = st[i].pSub; p < st[i].pSub + st[i].numSubject; p++) {
            p->name = (char *) malloc(sizeof(char) * (strlen(word[k]) + 1));
            strcpy(p->name, word[k]);
            k++;

            p->score = 0;
            for (char *q = word[k]; *q; q++) {
                p->score = p->score * 10 + *q - '0';
            }
            st[i].avg += p->score;
            k++;
        }

        st[i].avg /= st[i].numSubject;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].avg < st[j + 1].avg || (st[j].avg == st[j + 1].avg && strcmp(st[j].id, st[j + 1].id) > 0)) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1]  = tmp;
            }
        }
    }

    int K;
    scanf("%d", &K);
    K--;

    int maxIdx = 0;
    for (int i = 1; i < st[K].numSubject; i++) {
        if (st[K].pSub[i].score > st[K].pSub[maxIdx].score) {
            maxIdx = i;
        }
    }

    printf("%s %s %.2lf %s %.2lf\n", st[K].name, st[K].id, st[K].avg, st[K].pSub[maxIdx].name, st[K].pSub[maxIdx].score);

    return 0;
}