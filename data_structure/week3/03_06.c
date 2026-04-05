#include <stdio.h>

int count(char str[], char c) {
  if (str[0] == '\0')
    return 0;

  return (str[0] == c) + count(str + 1, c);
}

int main() {
  char str[101], c;

  scanf("%s %c", str, &c);

  printf("%d\n", count(str, c));

  return 0;
}