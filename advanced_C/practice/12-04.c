#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[8];
    int kor, eng, math;
    double avg;
};

int main() {
    int N;
    scanf("%d\n", &N);

    struct student *st = (struct student *) malloc(sizeof(struct student) * N);
    for (struct student *p = st; p < st + N; p++) {
        scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math);
        p->avg = (p->kor + p->eng + p->math) / 3.0;
    }

    for (struct student *p = st; p < st + N; p++) {
        printf("%s %.1f", p->name, p->avg);

        if (p->kor >= 90 || p->eng >= 90 || p->math >= 90) {
            printf(" GREAT");
        }

        if(p->kor < 70 || p->eng < 70 || p->math < 70) {
            printf(" BAD");
        }

        printf("\n");
    }
}