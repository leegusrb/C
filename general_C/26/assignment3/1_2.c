#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int min = 10000, min_num, max = 0, max_num;
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    int rev = 0;
    while (num > 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
    }

    int div = 0;
    for (int j = 1; j <= rev; j++) {
      if (rev % j == 0)
        div++;
    }

    if (div > max) {
      max = div;
      max_num = rev;
    }
    if (div < min) {
      min = div;
      min_num = rev;
    }

    printf("%d %d\n", rev, div);
  }

  printf("%d %d\n", max_num, min_num);

  return 0;
}