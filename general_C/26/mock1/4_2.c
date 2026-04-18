#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int cur, prev = 0;
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);

    int is_prime = 1;
    if (num <= 1) {
      is_prime = 0;
    } else {
      for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) {
          is_prime = 0;
          break;
        }
      }
    }

    if (is_prime) {
      cur = 1;
    } else if (num < 0) {
      cur = 2;
    } else {
      cur = 0;
    }

    if (cur == prev) {
      if (cur != 0) {
        printf("%d ", num);
      }
    } else {
      if (prev != 0) {
        printf("*\n");
      }

      if (cur != 0) {
        printf("%d ", num);
      }
    }

    prev = cur;
  }

  if (prev != 0) {
    printf("*\n");
  }

  return 0;
}