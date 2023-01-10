#include <stdio.h>

typedef struct {
    char name[10];
    int score;
} student;

int main() {
    student s[5];

    for (int i = 0; i < 5; i++) {
        scanf("%s %d", s[i].name, &s[i].score);
    }

    int tot = 0;
    for (int i = 0; i < 5; i++) {
        tot += s[i].score;
    }

    double avg = (double) tot / 5;
    for (int i = 0; i < 5; i++) {
        if (s[i].score <= avg) {
            printf("%s\n", s[i].name);
        }
    }

    return 0;
}
