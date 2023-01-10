#include <stdio.h>

typedef struct {
    int h, m, s;
} time;

int main() {
    time t1, t2, res;

    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    res.h = t2.h - t1.h;
    res.m = t2.m - t1.m;
    res.s = t2.s - t1.s;

    if (res.s < 0) {
        res.m--;
        res.s += 60;
    }
    if (res.m < 0) {
        res.h--;
        res.m += 60;
    }

    printf("%d %d %d\n", res.h, res.m, res.s);

    return 0;
}
