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

        p->name = (char *) malloc(sizeof(char) * (strlen(word[0]) + 1));
        p->numSubject = (wordN - 2) / 2;
        p->pSub = (struct subject *) malloc(sizeof(struct subject) * p->numSubject);

        strcpy(p->name, word[0]);
        strcpy(p->id, word[1]);

        int chk = 2;
        p->avg = 0;
        for (struct subject *q = p->pSub; chk < wordN; q++) {
            q->name = (char *) malloc(sizeof(char) * (strlen(word[chk]) + 1));
            strcpy(q->name, word[chk++]);

            q->score = 0;
            for (int j = 0; j < strlen(word[chk]); j++) {
                q->score = q->score * 10 + (word[chk][j] - '0');
            }

            p->avg += q->score;
            chk++;
        }

        p->avg /= p->numSubject;
    }

    sort(st, N);

    int K;
    scanf("%d", &K);
    K--;

    struct subject maxSub = st[K].pSub[0];
    for (int i = 1; i < st[K].numSubject; i++) {
        if (st[K].pSub[i].score > maxSub.score) {
            maxSub = st[K].pSub[i];
        }
    }

    printf("%s %s %.2lf %s %.2lf\n", st[K].name, st[K].id, st[K].avg, maxSub.name, maxSub.score);

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
            if (st[j].avg < st[j + 1].avg || (st[j].avg == st[j + 1].avg && strcmp(st[j].id, st[j + 1].id) > 0)) {
                struct student tmp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = tmp;
            }
        }
    }
}

void freeArr(struct student *st, int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < st[i].numSubject; j++) {
            free(st[i].pSub[j].name);
        }
        free(st[i].pSub);
        free(st[i].name);
    }
    free(st);
}