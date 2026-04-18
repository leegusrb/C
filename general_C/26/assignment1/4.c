#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int d2 = (n % 2 == 0);
  int d3 = (n % 3 == 0);
  int d5 = (n % 5 == 0);

  if (!d2 && !d3 && !d5) {
    printf("N\n");
  } else {
    if (d2)
      printf("2 ");
    if (d3)
      printf("3 ");
    if (d5)
      printf("5 ");
    printf("\n");
  }
  return 0;
}