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
    struct subject *psub;
    double avg;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);
    for (struct student *p = st; p < st + N; p++) {
        char studentName[101];
        scanf("%s %s", studentName, p->id);
        p->name = (char *) malloc(sizeof(char) * (strlen(studentName) + 1));
        strcpy(p->name, studentName);

        p->numSubject = 0;
        double sum = 0;
        while (1) {
            if (getchar() == '\n') break;

            char subjectName[101];
            double subjectScore;
            scanf("%s %lf", subjectName, &subjectScore);
            p->psub = (struct subject *) malloc(sizeof(struct student) * (++p->numSubject));
            p->psub[p->numSubject - 1].name = (char *) malloc(sizeof(char) * (strlen(subjectName) + 1));
            strcpy(p->psub[p->numSubject - 1].name, subjectName);
            p->psub[p->numSubject - 1].score = subjectScore;
            sum += subjectScore;
        }

        p->avg = sum / p->numSubject;
    }

    int K;
    scanf("%d", &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].avg < st[j + 1].avg || (st[j].avg == st[j + 1].avg && strcmp(st[j].id, st[j + 1].id) > 0)) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }

    struct subject max = st[K - 1].psub[0];

    for (int i = 1; i < st[K - 1].numSubject; i++) {
        printf("%lf\n", st[K - 1].psub[i].score);
        if (st[K - 1].psub[i].score > max.score) {
            max = st[K - 1].psub[i];
        }
    }

    printf("%s %s %.2lf %s %.2lf\n", st[K - 1].name, st[K - 1].id, st[K - 1].avg, max.name, max.score);

    for (struct student *p = st; p < st + N; p++) {
        for (struct subject *q = p->psub; q < p->psub + p->numSubject; q++) {
            free(q->name);
        }
        free(p->name);
        free(p->psub);
    }
    free(st);
}