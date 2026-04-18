#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0, cnt = 0;

  while (N >= 10) {
    while (N > 0) {
      sum += N % 10;
      N /= 10;
    }
    N = sum;
    cnt++;
    sum = 0;
  }

  printf("%d %d\n", N, cnt);

  return 0;
}