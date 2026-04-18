#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int is_prime = 1;
  if (N < 2)
    is_prime = 0;
  for (int i = 2; i < N; i++) {
    if (N % i == 0) {
      is_prime = 0;
      break;
    }
  }

  if (is_prime) {
    printf("prime\n");
  } else {
    int odd_sum = 0, even_sum = 0;
    for (int i = 1; i <= N; i++) {
      if (N % i == 0) {
        if (i % 2 == 1) {
          odd_sum += i;
        } else {
          even_sum += i;
        }
      }
    }
    printf("%d %d\n", even_sum, odd_sum);
  }

  return 0;
}