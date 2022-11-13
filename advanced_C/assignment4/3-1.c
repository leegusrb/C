#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char *studentName;
    char id[5];
    char *subjectName;
    double subjectScore;
};

int countWord(char *str);
void divide(char *str, char **word, int wordN);
void sort(struct student *st, int N);
void freeArr(struct student *st, int N);

int main() {
    int N;
    scanf("%d\n", &N);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);

    for (struct student *p = st; p < st + N; p++) {
        char str[101];
        gets(str);

        int wordN = countWord(str);
        char **word = (char **) malloc(sizeof(char *) * wordN);
        divide(str, word, wordN);

        p->studentName = (char *) malloc(sizeof(char) * (strlen(word[0]) + 1));
        p->subjectName = (char *) malloc(sizeof(char) * (strlen(word[2]) + 1));

        strcpy(p->studentName, word[0]);
        strcpy(p->id, word[1]);
        strcpy(p->subjectName, word[2]);

        p->subjectScore = 0;
        for (int j = 0; j < strlen(word[3]); j++) {
            p->subjectScore = p->subjectScore * 10 + (word[3][j] - '0');
        }
    }

    sort(st, N);

    int K;
    scanf("%d", &K);
    K--;

    printf("%s %s %s %.2lf\n", st[K].studentName, st[K].id, st[K].subjectName, st[K].subjectScore);

    freeArr(st, N);
}

int countWord(char *str){
    int wordN = 1;
    for (char *p = str; *p; p++) {
        if (*p == ' ') {
            wordN++;
        }
    }

    return wordN;
}

void divide(char *str, char **word, int wordN){
    char *start = str;
    int cnt = 0;
    wordN = 0;
    for (char *p = str; p <= str + strlen(str); p++) {
        if (*p == ' ' || *p == '\0') {
            word[wordN] = (char *) malloc(sizeof(char) * (cnt + 1));
            strncpy(word[wordN], start, cnt);
            word[wordN++][cnt] = '\0';
            start = p + 1;
            cnt = 0;
        } else {
            cnt++;
        }
    }
}

void sort(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (st[j].subjectScore < st[j + 1].subjectScore) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }
}

void freeArr(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        free(st[i].studentName);
        free(st[i].subjectName);
    }
    free(st);
}