#include <stdio.h>
#include <string.h>

void divide(char *str, char word[][101]);

int main() {
    int N, M1, M2;
    scanf("%d %d %d\n", &N, &M1, &M2);

    char str[20][101];
    int maxIdx = 0, minIdx = 0;
    for (int i = 0; i < N; i++) {
        gets(str[i]);

        if (strlen(str[i]) > strlen(str[maxIdx])) {
            maxIdx = i;
        }

        if (strlen(str[i]) < strlen(str[minIdx])) {
            minIdx = i;
        }
    }

    char words1[20][101], words2[20][101];
    divide(str[maxIdx], words1);
    divide(str[minIdx], words2);

    char new[101];
    if (strcmp(words1[M1], words2[M2]) < 0) {
        strcpy(new, words1[M1]);
        strcat(new, words2[M2]);
    } else {
        strcpy(new, words2[M2]);
        strcat(new, words1[M1]);
    }

    printf("%s\n%s\n%s\n", str[maxIdx], str[minIdx], new);

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

//5 4 2
//book desk pencil paper
//orange apple banana lemon prape
//red yellow green orange blue white black
//candy cake icecream
//july august september october november december