#include <stdio.h>

int count(char *str, char c);

int check(char c1, char c2);

int main() {
    char str[101], c;
    scanf("%s\n%c", str, &c);

    printf("%d\n", count(str, c));

    return 0;
}

int count(char *str, char c) {
    if (!str[0]) return 0;

    return check(str[0], c) + count(str + 1, c);
}

int check(char c1, char c2) {
    return c1 == c2;
}