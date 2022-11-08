#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWord(char *str);
void divide(char *str, char **word, int wordN);
void sort(char **word, int wordN);
void freeArr(char **word, int wordN);

int main() {
    char str1[101], str2[101];
    gets(str1);
    gets(str2);

    int word1N = countWord(str1);
    int word2N = countWord(str2);
    char **word1 = (char **) malloc(sizeof(char *) * word1N);
    char **word2 = (char **) malloc(sizeof(char *) * word2N);
    divide(str1, word1, word1N);
    divide(str2, word2, word2N);
    sort(word1, word1N);
    sort(word2, word2N);

    for (int i = 0, j = 0; i < word1N && j < word2N; ) {
        if (strlen(word1[i]) > strlen(word2[j])) {
            i++;
        } else if (strlen(word1[i]) < strlen(word2[j])) {
            j++;
        } else if (strcmp(word1[i], word2[j]) < 0) {
            i++;
        } else if (strcmp(word1[i], word2[j]) > 0) {
            j++;
        } else {
            printf("%s\n", word1[i]);
            i++;
            j++;
        }
    }

    freeArr(word1, word1N);
    freeArr(word2, word2N);
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

void sort(char **word, int wordN){
    for (int i = 0; i < wordN; i++) {
        for (int j = 0; j < wordN - 1 - i; j++) {
            if (strlen(word[j]) < strlen(word[j + 1]) || strlen(word[j]) == strlen(word[j + 1]) && strcmp(word[j], word[j + 1]) > 0) {
                char *tmp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = tmp;
            }
        }
    }
}

void freeArr(char **word, int wordN){
    for (int i = 0; i < wordN; i++) {
        free(word[i]);
    }
    free(word);
}