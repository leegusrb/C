#include <stdio.h>

void swap(int *p1, int *p2);

int main() {
    int N, arr[51], a, b;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &a, &b);

    swap(arr + a, arr + b);

    for (int i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}