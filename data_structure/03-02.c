#include <stdio.h>

void printDigits(int n);

int main() {
    int n;
    scanf("%d", &n);

    printDigits(n);

    return 0;
}

void printDigits(int n) {
    if (n < 10) {
        printf("%d\n", n);
        return;
    }
    
    printDigits(n / 10);
    printf("%d\n", n % 10);
}