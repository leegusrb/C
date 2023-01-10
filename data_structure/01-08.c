#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[8];
    int kor, eng, mth;
    double avg;
} student;

int main() {
    int N;
    scanf("%d", &N);

    student *s = (student *) malloc(sizeof(student) * N);

    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %d", s[i].name, &s[i].kor, &s[i].eng, &s[i].mth);
        s[i].avg = (double) (s[i].kor + s[i].eng + s[i].mth) / 3;
    }

    for (int i = 0; i < N; i++) {
        printf("%s %.1lf", s[i].name, s[i].avg);
        if (s[i].kor >= 90 || s[i].eng >= 90 || s[i].mth >= 90) {
            printf(" GREAT");
        }
        if (s[i].kor < 70 || s[i].eng < 70 || s[i].mth < 70) {
            printf(" BAD");
        }
        printf("\n");
    }

    return 0;
}
