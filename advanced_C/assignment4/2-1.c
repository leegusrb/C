#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[101];
    gets(str);

    int wordN = 1;
    for (char *p = str; *p; p++) {
        if (*p == ' ') {
            wordN++;
        }
    }

    char **word = (char **) malloc(sizeof(char *) * wordN);
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

    for (int i = 0; i < wordN; i++) {
        for (int j = 0; j < wordN - 1 - i; j++) {
            if (strlen(word[j]) < strlen(word[j + 1]) || strlen(word[j]) == strlen(word[j + 1]) && strcmp(word[j], word[j + 1]) > 0) {
                char *tmp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < wordN; i++) {
        printf("%s\n", word[i]);
    }

    for (int i = 0; i < wordN; i++) {
        free(word[i]);
    }
    free(word);
}