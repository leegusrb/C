#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *str;
    int words;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct string *string = (struct string *) malloc(sizeof(struct string) * N);
    for (struct string *p = string; p < string + N; p++) {
        char tmp[101];
        gets(tmp);

        p->str = (char *) malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(p->str, tmp);

        p->words = 1;
        for (char *q = p->str; *q; q++) {
            if (*q == ' ') {
                p->words++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (string[j].words < string[j + 1].words) {
                struct string tmp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = tmp;
            }
        }
    }

    for (struct string *p = string; p < string + N; p++) {
        printf("%s %d\n", p->str, p->words);
    }

    for (struct string *p = string; p < string + N; p++) {
        free(p->str);
    }
    free(string);

    return 0;
}