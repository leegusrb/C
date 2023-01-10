#include <stdio.h>

int sum(int n);

int main() {
    int X;
    scanf("%d", &X);

    int tot = 0;
    for (int i = 1; i <= X; i++) {
        tot += sum(i);
    }

    printf("%d\n", tot);

    return 0;
}

int sum(int n) {
    int tot = 0;

    for (int i = 1; i <= n; i++) {
        tot += i;
    }

    return tot;
}