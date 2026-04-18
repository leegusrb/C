#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int odd_max = -10000, even_min = 10000;
  for (int i = 1; i <= N; i++) {
    int num;
    scanf("%d", &num);

    if (i % 2 == 1) {
      if (num > odd_max)
        odd_max = num;
    } else {
      if (num < even_min)
        even_min = num;
    }
  }

  printf("%d\n", odd_max - even_min);

  return 0;
}