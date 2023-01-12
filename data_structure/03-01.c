#include <stdio.h>

int sum(int N);

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", sum(N));

    return 0;
}

int sum(int N) {
    if (N == 1) return 1;

    return N + sum(N - 1);
}