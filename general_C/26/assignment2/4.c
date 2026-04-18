#include <stdio.h>

int main() {
  int even_pos = 0, odd_neg = 0;

  while (1) {
    int num;
    scanf("%d", &num);

    if (num > 1000 || num < -1000)
      break;

    if (num > 0 && num % 2 == 0)
      even_pos = 1;
    else if (num < 0 && num % 2 != 0)
      odd_neg = 1;
  }

  if (even_pos == 0 && odd_neg == 0)
    printf("none\n");
  else {
    if (even_pos)
      printf("P ");
    if (odd_neg)
      printf("N ");
    printf("\n");
  }

  return 0;
}