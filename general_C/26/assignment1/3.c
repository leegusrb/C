#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  int cnt = 0;

  if (n % 2 == 0)
    cnt++;
  if (n % 3 == 0)
    cnt++;
  if (n % 5 == 0)
    cnt++;

  if (cnt == 3) {
    printf("A\n");
  } else if (cnt == 2) {
    printf("B\n");
  } else if (cnt == 1) {
    printf("C\n");
  } else {
    printf("D\n");
  }

  return 0;
}