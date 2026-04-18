#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int min = 10000, max = 0;

  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    int rev = 0;
    while (num > 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
    }

    if (rev < min)
      min = rev;
    if (rev > max)
      max = rev;

    printf("%d\n", rev);
  }

  printf("%d %d\n", max, min);

  return 0;
}