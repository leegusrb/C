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

        p->sum = p->firstStage * 0.7 + p->interview * 0.3;
    }

    sort(st, N);

    for (struct student *p = st; p < st + M; p++) {
        printf("%s %.1lf\n", p->name, p->sum);
    }

    freeArr(st, N);
}

void sort(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].sum < st[j + 1].sum) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }
}

void freeArr(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        free(st[i].name);
    }
    free(st);
}