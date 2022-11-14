#include <stdio.h>
#include <string.h>

void divide(char *str, char word[][101]);

int main() {
    int M, N;
    scanf("%d %d\n", &M, &N);

    char str[101], words1[20][101], words2[20][101];
    gets(str);
    divide(str, words1);
    gets(str);
    divide(str, words2);

    if (strcmp(words1[M], words2[N]) < 0) {
        strcpy(str, words1[M]);
        strcat(str, words2[N]);
    } else {
        strcpy(str, words2[N]);
        strcat(str, words1[M]);
    }

    printf("%s\n", str);

    return 0;
}

void divide(char *str, char word[][101]){
    int i = 0, j = 0;
    for (char *p = str; p <= str + strlen(str); p++) {
        if (*p == ' ' || *p == '\0') {
            word[i++][j] = '\0';
            j = 0;
        } else {
            word[i][j++] = *p;
        }
    }
}