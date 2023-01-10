#include <stdio.h>

void ABC(int *arr, int k);

int main() {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        ABC(arr, i);
    }
    
    for (int i = 0; i < 10; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}

void ABC(int *arr, int k) {
    int maxIdx = k;

    for (int i = k + 1; i < 10; i++) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }

    int tmp = arr[k];
    arr[k] = arr[maxIdx];
    arr[maxIdx] = tmp;
}