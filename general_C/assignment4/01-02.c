#include <stdio.h>

int main() {
    int M1, M2, N, X[100], Y[100];
    scanf("%d %d", &M1, &M2);

    int cnt = 0;
    while (1) {
        scanf("%d", &N);
        if (N <= 0) break;

        int idx = 0;
        for (int i = 0, n = N; n > 0; i++, n /= 10) {
            if (i != M1 && i != M2)
                Y[idx++] = n % 10;
        }

        int flag = 0;
        for (int i = 0; i < idx / 2; i++) {
            if (Y[i] != Y[idx - 1 - i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            X[cnt++] = N;
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < i; j++) {
            if (X[i] > X[j]) {
                int tmp = X[i];
                X[i] = X[j];
                X[j] = tmp;
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        printf("%d ", X[i]);
    }

    return (0);
}

/*
 * 1 3
 * 12021 345433 12345 1022201 768833 2334 77907 12321 37773 -1
 */