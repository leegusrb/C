#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *studentName;
    char id[5];
    char *subjectName;
    double subjectScore;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);
    for (struct student *p = st; p < st + N; p++) {
        char tmp1[101], tmp2[101];
        scanf("%s %s %s %lf", tmp1, p->id, tmp2, &p->subjectScore);
        p->studentName = (char *) malloc(sizeof(char) * (strlen(tmp1) + 1));
        p->subjectName = (char *) malloc(sizeof(char) * (strlen(tmp2) + 1));
        strcpy(p->studentName, tmp1);
        strcpy(p->subjectName, tmp2);
    }

    int K;
    scanf("%d", &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].subjectScore < st[j + 1].subjectScore) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }

    printf("%s %s %s %.2lf\n", st[K - 1].studentName, st[K - 1].id, st[K - 1].subjectName, st[K - 1].subjectScore);

    for (struct student *p = st; p < st + N; p++) {
        free(st->studentName);
        free(st->subjectName);
    }
    free(st);
}