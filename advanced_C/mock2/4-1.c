#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reserve {
    int id;
    char grade[4];
    int price;
};

void input(struct reserve *p, int N);
int cal_sum(struct reserve *p, int N, int id);
int price(char *grade);

int main() {
    int N;
    scanf("%d", &N);

    struct reserve *res = (struct reserve *) malloc(sizeof(struct reserve) * N);
    input(res, N);

    int id;
    scanf("%d", &id);

    printf("%d\n", cal_sum(res, N, id));

    return 0;
}

void input(struct reserve *p, int N) {
    for (struct reserve *q = p; q < p + N; q++) {
        scanf("%d %s", &q->id, q->grade);
        q->price = price(q->grade);
    }
}

int cal_sum(struct reserve *p, int N, int id){
    int sum = 0;
    for (struct reserve *q = p; q < p + N; q++) {
        if (q->id == id) {
            printf("%s %d\n", q->grade, q->price);
            sum += q->price;
        }
    }

    return sum;
}

int price(char *grade){
    if (strcmp(grade, "VIP") == 0) {
        return 140000;
    } else if (strcmp(grade, "R") == 0) {
        return 110000;
    } else if (strcmp(grade, "S") == 0) {
        return 85000;
    } else if (strcmp(grade, "A") == 0) {
        return 55000;
    }

    return -1;
}