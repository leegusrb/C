#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reserve {
    int id;
    char grade[4];
    int price;
};

struct tot_price {
    int id;
    int total_price;
};

void input(struct reserve *p, int N);

int cal_num(struct reserve *p, int N);

void cal_sum(struct reserve *p, int N, struct tot_price *q);

int price(char *grade);

int main() {
    int N;
    scanf("%d", &N);

    struct reserve *res = (struct reserve *) malloc(sizeof(struct reserve) * N);
    input(res, N);

    int cnt = cal_num(res, N);
    struct tot_price *tot = (struct tot_price *) malloc(sizeof(struct tot_price) * cnt);

    cal_sum(res, N, tot);

    for (struct tot_price *p = tot; p < tot + cnt; p++) {
        printf("%d %d\n", p->id, p->total_price);
    }

    free(res);
    free(tot);

    return 0;
}

void input(struct reserve *p, int N) {
    for (struct reserve *q = p; q < p + N; q++) {
        scanf("%d %s", &q->id, q->grade);
        q->price = price(q->grade);
    }
}

int cal_num(struct reserve *p, int N) {
    int cnt = 0;
    for (struct reserve *x = p; x < p + N; x++) {
        int flag = 0;
        for (struct reserve *y = p; y < x; y++) {
            if (x->id == y->id) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cnt++;
        }
    }

    return cnt;
}

void cal_sum(struct reserve *p, int N, struct tot_price *q) {
    struct tot_price *totN = q;
    for (struct reserve *x = p; x < p + N; x++) {
        int flag = 0;
        for (struct tot_price *y = q; y < totN; y++) {
            if (y->id == x->id) {
                y->total_price += x->price;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            totN->id = x->id;
            totN->total_price = x->price;
            totN++;
        }
    }
}

int price(char *grade) {
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
/*
10
123 A
210 VIP
123 A
123 R
210 S
210 VIP
123 A
523 A
123 R
523 VIP
 */