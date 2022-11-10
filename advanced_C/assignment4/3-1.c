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
        char studentName[101], subjectName[101];
        scanf("%s %s %s %lf", studentName, p->id, subjectName, &p->subjectScore);
        p->studentName = (char *) malloc(sizeof(char) * (strlen(studentName) + 1));
        p->subjectName = (char *) malloc(sizeof(char) * (strlen(subjectName) + 1));
        strcpy(p->studentName, studentName);
        strcpy(p->subjectName, subjectName);
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