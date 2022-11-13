#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *name;
    int firstStage;
    int interview;
    double sum;
};

void sort(struct student *st, int N);
void swap(struct student *st1, struct student *st2);
void freeArr(struct student *st, int N);

int main() {
    int N, M;
    scanf("%d %d\n", &N, &M);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);

    for (struct student *p = st; p < st + N; p++) {
        char name[11];
        scanf("%s %d %d", name, &p->firstStage, &p->interview);

        p->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
        strcpy(p->name, name);

        p->sum = p->firstStage * 7 + p->interview * 3;
    }

    sort(st, N);

    int cnt = 1;
    for (struct student *p = st; p < st + M; p++) {
        printf("%s %d %d %.1lf\n", p->name, p->firstStage, p->interview, p->sum / 10);
        if (p == st + M - 1) {
            while (p->sum == (p + cnt)->sum && p->firstStage == (p + cnt)->firstStage) {
                printf("%s %d %d %.1lf\n", (p + cnt)->name, (p + cnt)->firstStage, (p + cnt)->interview, (p + cnt)->sum / 10);
                cnt++;
            }
        }
    }
    printf("%d\n", M + cnt - 1);

    freeArr(st, N);
}

void sort(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].sum < st[j + 1].sum) {
                swap(st + j, st + j + 1);
            } else if (st[j].sum == st[j + 1].sum && st[j].firstStage < st[j + 1].firstStage) {
                swap(st + j, st + j + 1);
            } else if (st[j].sum == st[j + 1].sum && st[j].firstStage == st[j + 1].firstStage && strcmp(st[j].name, st[j + 1].name) > 0) {
                swap(st + j, st + j + 1);
            }
        }
    }
}

void swap(struct student *st1, struct student *st2){
    struct student tmp = *st1;
    *st1 = *st2;
    *st2 = tmp;
}

void freeArr(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        free(st[i].name);
    }
    free(st);
}
