#include <stdio.h>

int modulo(int a, int b) {
  while (a >= b) {
    a -= b;
  }

  return a;
}

int main() {
  int a, b;

  scanf("%d %d", &a, &b);

  printf("%d", modulo(a, b));

  return 0;
}