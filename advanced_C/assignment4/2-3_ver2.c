#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char A[101], B[101];
    gets(A);
    gets(B);

    int cntA = 1, cntB = 1;
    for (char *p = A; *p != '\0'; p++) {
        if (*p == ' ') {
            cntA++;
        }
    }
    for (char *p = B; *p != '\0'; p++) {
        if (*p == ' ') {
            cntB++;
        }
    }

    char **wordA = (char **) malloc(sizeof(char *) * cntA);
    char **wordB = (char **) malloc(sizeof(char *) * cntB);
    // abc def
    char *start = A;
    int x = 0, cnt = 0;
    for (char *p = A; p <= A + strlen(A); p++) {
        if (*p == ' ' || *p == '\0') {
            wordA[x] = (char *) malloc(sizeof(char *) * (cnt + 1));
            strncpy(wordA[x], start, cnt);
            wordA[x][cnt] = '\0';
            start = p + 1;
            x++;
            cnt = 0;
        } else {
            cnt++;
        }
    }

    start = B;
    x = 0;
    cnt = 0;
    for (char *p = B; p <= B + strlen(B); p++) {
        if (*p == ' ' || *p == '\0') {
            wordB[x] = (char *) malloc(sizeof(char *) * (cnt + 1));
            strncpy(wordB[x], start, cnt);
            wordB[x][cnt] = '\0';
            start = p + 1;
            x++;
            cnt = 0;
        } else {
            cnt++;
        }
    }

    cnt = 0;
    for (int i = 0; i < cntA; i++) {
        for (int j = 0; j < cntA; j++) {
            if (i == j) continue;

            char tmp[101] = "";
            strcpy(tmp, wordA[i]);
            strcat(tmp, wordA[j]);
            for (int k = cnt; k < cntB; k++) {
                if (strcmp(tmp, wordB[k]) == 0) {
                    char *word = wordB[k];
                    wordB[k] = wordB[cnt];
                    wordB[cnt] = word;
                    cnt++;
                }
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt - 1 - i; j++) {
            if (strlen(wordB[j]) < strlen(wordB[j + 1]) ||
                (strlen(wordB[j]) == strlen(wordB[j + 1]) && strcmp(wordB[j], wordB[j + 1]) > 0)) {
                char *tmp = wordB[j];
                wordB[j] = wordB[j + 1];
                wordB[j + 1] = tmp;
            }
        }
    }
    
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", wordB[i]);
    }
    
    // 해제!!
}